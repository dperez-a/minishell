#include "../../minishell.h"

// t_token **split_by_pipes(t_token *tokens, int *num_pipes)
// {
//     t_token **segments = NULL;
//     t_token *current = tokens;
//     int count = 1;

//     // Contar pipes para determinar el número de segmentos
//     while (current)
//     {
//         if (current->type == PIPE)
//         {
//             if (!current->next || current->next->type == PIPE)
//             {
//                 printf("Error: Pipe inesperado.\n");
//                 return NULL; // Error si hay pipes consecutivos o al final
//             }
//             count++;
//         }
//         current = current->next;
//     }
//     *num_pipes = count;

//     // Reservar memoria para los segmentos
//     segments = ft_calloc(count + 1, sizeof(t_token *));
//     if (!segments)
//         return NULL; // Evitar fugas de memoria

//     // Reiniciar puntero para dividir tokens
//     current = tokens;
//     int i = 0;
//     segments[i++] = tokens;

//     while (current)
//     {
//         if (current->type == PIPE)
//         {
//             t_token *next_segment = current->next;
//             current->next = NULL; // Rompemos la lista
//             segments[i++] = next_segment;
//         }
//         current = current->next;
//     }

//     return segments;
// }

t_pipeline  *process_pipeline(t_token *tokens, int num_pipes)
{
    t_token **segments = split_by_pipes(tokens, &num_pipes);
    if (!segments)
        return NULL;
    t_pipeline *pipeline = ft_calloc (1, sizeof(t_pipeline));
    if (!pipeline->commands)
        return NULL;

    pipeline->count = num_pipes;
}

t_token **split_by_pipes(t_token *tokens, int *num_pipes)
{
    t_token **segments = NULL;
    t_token *current = tokens;
    int count = 1; // Contamos al menos un segmento

    // Contar pipes para saber cuántos segmentos tendremos
    while (current)
    {
        if (current->type == PIPE)
        {
            if (!current->next || current->next->type == PIPE)
            {
                printf("Error: Pipe inesperado.\n");
                return NULL; // Error si hay pipes consecutivos o al final
            }
            count++;
        }
        current = current->next;
    }
    *num_pipes = count;

    // Reservar memoria para los segmentos
    segments = ft_calloc(count + 1, sizeof(t_token *));
    if (!segments)
        return (NULL);

    // Dividir tokens por pipes
    current = tokens;
    int i = 0;
    segments[i++] = tokens;

    while (current)
    {
        if (current->type == PIPE)
        {
            t_token *next_segment = current->next;
            current->next = NULL; // Rompemos la lista aquí
            segments[i++] = next_segment;
            if (!next_segment) // 🚨 Verificación adicional
            {
                printf("Error: Pipe sin contenido después en posición %d\n", i);
                free(segments);
                return NULL;
            }
        }
        current = current->next;
    }
    return segments;
}

t_command *process_segments(t_token *tokens)
{
    t_command *command = ft_calloc(1, sizeof(t_command));
    if (!command)
        return NULL;
    // Inicializar valores predeterminados
    command->command = NULL;
    command->input_file = NULL;
    command->output_file = NULL;
    command->input_redir_type = 0;
    command->output_redir_type = 0;
    // Buscar el comando principal
    while (tokens && tokens->type != WORD)
        tokens = tokens->next;
    if (tokens && tokens->type == WORD) {
        command->command = ft_strdup(tokens->str);
        tokens = tokens->next;
    } else {
        printf("Error: No se encontró un comando válido.\n");
        free(command);
        return NULL;
    }
    // Llamar a funciones para manejar redirecciones específicas
    while (tokens) {
        tokens = handle_redirection(tokens, command);
        if (!tokens) {
            free(command);
            return NULL;
        }
        tokens = tokens->next;
    }
    return command;
}


//! print pipeline orginial, no borrar de momento
// void print_pipeline(t_pipeline *pipeline)
// {
//     printf("\nPipeline con %d comandos:\n", pipeline->count);
//     int i = 0;
//     while (i < pipeline->count)
//     {
//         t_command *cmd = pipeline->commands[i];
//         printf("Comando %d: %s\n", i + 1, cmd->command ? cmd->command : "None");
//         printf("  Archivo entrada: %s\n", cmd->input_file ? cmd->input_file : "None");
//         printf("  Archivo salida: %s\n", cmd->output_file ? cmd->output_file : "None");
//         printf("  Tipo redirección entrada: %d\n", cmd->input_redir_type);
//         printf("  Tipo redirección salida: %d\n", cmd->output_redir_type);
//         i++;
//     }
// }


void print_pipeline(t_pipeline *pipeline)
{
    printf("\nPipeline con %d comandos:\n", pipeline->count);
    int i = 0;
    while (i < pipeline->count)
    {
        t_command *cmd = pipeline->commands[i];
        printf("Comando %d: %s\n", i + 1, cmd->command ? cmd->command : "None");
        printf("  Archivo entrada: %s\n", cmd->input_file ? cmd->input_file : "None");
        printf("  Archivo salida: %s\n", cmd->output_file ? cmd->output_file : "None");
        printf("  Tipo redirección entrada: %d\n", cmd->input_redir_type);
        printf("  Tipo redirección salida: %d\n", cmd->output_redir_type);
        
        // Verificar y separar el comando y los argumentos
        if (cmd->args != NULL) {
            printf("  Argumentos: ");
            int j = 0;
            // Aquí se asegura de no imprimir el comando en los argumentos
            while (cmd->args[j] != NULL)
            {
                if (j > 0)  // Si ya estamos en el primer argumento, los imprimimos
                    printf("%s ", cmd->args[j]);
                j++;
            }
            printf("\n");
        } else {
            printf("  Argumentos: None\n");
        }

        i++;
    }
}
