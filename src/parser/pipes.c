#include "../../minishell.h"

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
        }
        current = current->next;
    }
    return (segments);
}

t_pipeline *process_pipeline(t_token *tokens)
{
    int num_pipes;
    t_token **segments = split_by_pipes(tokens, &num_pipes);
    if (!segments)
        return NULL;
    t_pipeline *pipeline = ft_calloc(1, sizeof(t_pipeline));
    if (!pipeline)
    {
        free(segments);
        return NULL;
    }
    pipeline->commands = ft_calloc(num_pipes, sizeof(t_command *));
    if (!pipeline->commands)
    {
        free(pipeline);
        free(segments);
        return NULL;
    }
    pipeline->count = num_pipes;

    int i = 0;
    while (i < num_pipes)
    {
        pipeline->commands[i] = process_redirection_tokens(&segments[i]);
        if (!pipeline->commands[i])
        {
            printf("Error: Fallo en el comando %d\n", i + 1);
            free_pipeline(pipeline); // Ahora existe esta función
            free(segments);
            return NULL;
        }
        i++;
    }

    free(segments);
    return pipeline;
}

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
        i++;
    }
}
