#include "../../minishell.h"

// Imprime la lista básica de tokens
void print_tokens(t_token *tokens)
{
    printf("Lista de tokens:\n");
    while (tokens)
    {
        printf("Token: '%s', Type: %d\n", tokens->str, tokens->type);
        tokens = tokens->next;
    }
    printf("----------------------\n");
}

int main()
{
    // Definimos algunas cadenas de prueba
    const char *inputs[] = {
        "cat 'hello world'",
        // "ls -la | grep minishell > result.txt",
        // "cat < input.txt | sort > sorted.txt",
        // "echo 'Hello, World!' >> greetings.txt",
        // "export PATH=$PATH:/new/path",
        NULL
    };

    int i = 0;

    while (inputs[i] != NULL)
    {
        printf("\nProcesando input: %s\n", inputs[i]);

        // Creamos la estructura de datos para el lexer
        t_data data;
        data.token = NULL;
        data.user_input = (char *)inputs[i];

        // Ejecutamos la tokenización
        if (tokenization(&data, data.user_input) == 0)
        {
            // Usamos las funciones de depuración
            print_token_list(&data.token); // Depuración detallada de la lista de tokens
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

