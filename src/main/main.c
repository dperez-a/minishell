#include "../../minishell.h"

// //! main to test how tokenization works
// int main()
// {
//     // Definimos algunas cadenas de prueba
//     const char *inputs[] = {
//         // "cat 'hello world'",
//         // "echo Hola que tal | grep a",
//         // "ls -la | grep minishell > result.txt'",
//         "cat < input.txt | sort > sorted.txt",
//         // "echo 'Hello, World!' >> greetings.txt",
//         // "export PATH=$PATH:/new/path",

//         NULL
//     };

//     int i = 0;

//     while (inputs[i] != NULL)
//     {
//         printf("\nProcesando input: %s\n", inputs[i]);

//         // Creamos la estructura de datos para el lexer
//         t_data data;
//         data.token = NULL;
//         data.user_input = (char *)inputs[i];

//         // Ejecutamos la tokenización
//         if (tokenization(&data, data.user_input) == 0)
//         {
//             // Usamos las funciones de depuración
//             print_token_list(&data.token); // Depuración detallada de la lista de tokens
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

int main()
{
    // Definimos algunas cadenas de prueba
    const char *inputs[] = {
        "cat < input.txt | sort > sorted.txt",
        // "echo Hola que tal | grep a | wc -l > output.txt",
        NULL
    };

    int i = 0;

    while (inputs[i] != NULL)
    {
        printf("\nProcesando input: %s\n", inputs[i]);

        // Crear la estructura de datos para el lexer
        t_data data;
        data.token = NULL;
        data.user_input = (char *)inputs[i];

        // Ejecutamos la tokenización
        if (tokenization(&data, data.user_input) == 0)
        {
            // Usamos las funciones de depuración para los tokens
            print_token_list(&data.token);

            // Procesamos el pipeline
            t_pipeline *pipeline = process_pipeline(data.token);
            if (pipeline)
            {
                print_pipeline(pipeline); // Imprimimos la estructura del pipeline
                // Liberar la memoria del pipeline después del uso
                for (int j = 0; j < pipeline->count; j++)
                {
                    free(pipeline->commands[j]->command);
                    free(pipeline->commands[j]->input_file);
                    free(pipeline->commands[j]->output_file);
                    free(pipeline->commands[j]);
                }
                free(pipeline->commands);
                free(pipeline);
            }
            else
            {
                printf("Error: Falló el procesamiento del pipeline.\n");
            }
        }
        else
        {
            printf("Error al tokenizar la cadena: %s\n", inputs[i]);
        }

        // Liberamos la memoria de la lista de tokens después de cada prueba
        t_token *tmp;
        while (data.token)
        {
            tmp = data.token;
            data.token = data.token->next;
            free(tmp->str);
            free(tmp->str_backup);
            free(tmp);
        }

        i++;
    }

    return 0;
}
