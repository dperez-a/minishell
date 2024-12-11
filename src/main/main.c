#include "../../minishell.h"

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
        "echo hello world",
        "ls -la | grep minishell > result.txt",
        "cat < input.txt | sort > sorted.txt",
        "echo 'Hello, World!' >> greetings.txt",
        "export PATH=$PATH:/new/path",
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
            print_tokens(data.token);
        }
        else
        {
            printf("Error al tokenizar la cadena: %s\n", inputs[i]);
        }

        i++;
    }

    return 0;
}
