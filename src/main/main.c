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
    const char *inputs[] =
    {
        // "echo Hello world",
        // "echo Hello World > output.log",
        // "ls -la | grep minishell > result.txt",
        // "ls -l | grep 'minishell' | awk '{print $1}'",
        // "cat < input.txt | sort > sorted.txt",
        // "echo 'Hello, World!' >> to_do.txt",
        // "export PATH=$PATH:/new/path",
        //!errores
        "ls -la |",
        "cat non_existent_file.txt > nonexistent_output.txt",
        "echo 'Unclosed quote",
        "echo $UNDEFINED_VAR",
        "ls  -l >   > output.txt",
        NULL
    };

    int i = 0;

    while (inputs[i] != NULL)
    {
        printf("\nProcesando input: %s\n", inputs[i]);

        // date struct for the lexer
        t_data data;
        data.token = NULL;
        data.user_input = (char *)inputs[i];

        // tokenize execution
        if (tokenization(&data, data.user_input) == 0)
            // deb functions
            print_token_list(&data.token); // token list depuration
        else
            printf("Error al tokenizar la cadena: %s\n", inputs[i]);

        // free the memory of the tokens after the test
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

