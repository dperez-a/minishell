#include "../../minishell.h"

int main(void)
{
    t_data data;

    // Inicializar el entorno
    init_environment(&data);

    // Definir el prompt con color y emoticono
    const char *prompt_color = "\033[90m";  // Gris semi-transparente
    const char *reset_color = "\033[0m";    // Resetear color
    const char *prompt_emoticon = "🐚 ";
    char *prompt = NULL;

    // Construir el prompt
    asprintf(&prompt, "%s%sminiconcha> %s", prompt_color, prompt_emoticon, reset_color);

    while (true)
    {
        data.user_input = readline(prompt);
        if (!data.user_input)
        {
            printf("\nSalir de miniconcha 🐚\n");
            break;
        }

        if (*data.user_input)
            add_history(data.user_input);

        data.token = NULL;
        if (tokenization(&data, data.user_input) == 0)
        {
            int num_pipes;
            t_token **segments = split_by_pipes(data.token, &num_pipes);

            printf("\nNúmero de comandos: %d\n", num_pipes);
            for (int i = 0; i < num_pipes; i++)
            {
                printf("\nComando %d:\n", i + 1);
                print_token_list(&segments[i]);
            }
            free(segments);
        }
        else
        {
            printf("Error al tokenizar la entrada.\n");
        }

        lstclear_token(&data.token, free);
        free(data.user_input);
    }

    free(prompt);
    return 0;
}




//! main to test if the tokens and the pipes split are working
// int main()
// {
//     // Definimos algunas cadenas de prueba
//     const char *inputs[] = {
//         "cat < input.txt | sort > sorted.txt",
//         // "echo Hola que tal | grep a | wc -l > output.txt",
//         NULL
//     };

//     int i = 0;

//     while (inputs[i] != NULL)
//     {
//         printf("\nProcesando input: %s\n", inputs[i]);

//         // Crear la estructura de datos para el lexer
//         t_data data;
//         data.token = NULL;
//         data.user_input = (char *)inputs[i];

//         // Ejecutamos la tokenización
//         if (tokenization(&data, data.user_input) == 0)
//         {
//             // Usamos las funciones de depuración para los tokens
//             print_token_list(&data.token);

//             // Procesamos el pipeline
//             t_pipeline *pipeline = process_pipeline(data.token);
//             if (pipeline)
//             {
//                 print_pipeline(pipeline); // Imprimimos la estructura del pipeline
//                 // Liberar la memoria del pipeline después del uso
//                 for (int j = 0; j < pipeline->count; j++)
//                 {
//                     free(pipeline->commands[j]->command);
//                     free(pipeline->commands[j]->input_file);
//                     free(pipeline->commands[j]->output_file);
//                     free(pipeline->commands[j]);
//                 }
//                 free(pipeline->commands);
//                 free(pipeline);
//             }
//             else
//             {
//                 printf("Error: Falló el procesamiento del pipeline.\n");
//             }
//         }
//         else
//         {
//             printf("Error al tokenizar la cadena: %s\n", inputs[i]);
//         }

//         // Liberamos la memoria de la lista de tokens después de cada prueba
//         t_token *tmp;
//         while (data.token)
//         {
//             tmp = data.token;
//             data.token = data.token->next;
//             free(tmp->str);
//             free(tmp->str_backup);
//             free(tmp);
//         }

//         i++;
//     }

//     return 0;
// }

// //! main para el entorno
// int main(int argc, char **argv, char **envp)
// {
//     (void)argc;
//     (void)argv;

//     t_data data = {0};
//     initialize_env(&data, envp);

//     // Probar el comando `env`
//     printf("Variables de entorno iniciales:\n");
//     env_builtin(data.env_vars);

//     // Probar `export`
//     printf("\nAñadiendo PATH_TEST...\n");
//     export_builtin(&data.env_vars, "PATH_TEST", "/usr/local/bin");
//     env_builtin(data.env_vars);

//     // Probar `unset`
//     printf("\nEliminando PATH_TEST...\n");
//     unset_builtin(&data.env_vars, "PATH_TEST");
//     env_builtin(data.env_vars);

//     return 0;
// }
