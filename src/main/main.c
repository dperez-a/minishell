#include "../../minishell.h"

void test_tokenize_input(const char *input)
{
    printf("Input: %s\n", input);
    t_token *tokens = tokenize_input(input);
    print_tokens(tokens);

    // Procesar las redirecciones y construir los comandos
    t_token *current_token = tokens;
    while (current_token) {
        if (current_token->type == REDIR_IN || current_token->type == REDIR_OUT || 
            current_token->type == APPEND || current_token->type == HEREDOC) {
            t_command *command = process_redirection_tokens(&current_token);
            // Imprimir la información del comando procesado
            if (command) {
                printf("Command: %s\n", command->command);
                printf("Input File: %s\n", command->input_file ? command->input_file : "None");
                printf("Output File: %s\n", command->output_file ? command->output_file : "None");
            }
        }
        current_token = current_token->next;
    }

    // Liberar tokens después de su uso
    t_token *tmp;
    while (tokens)
    {
        tmp = tokens;
        tokens = tokens->next;
        free(tmp->value);
        free(tmp);
    }
    printf("\n");
}

int main()
{
    // Casos de prueba
    const char *inputs[] =
    {
        "echo $USER | grep 'hello world' > output.txt",
        "ls -la | grep minishell > result.txt",
        "cat < input.txt | sort > sorted.txt",
        "echo 'Hello, World!' >> greetings.txt",
        "export PATH=$PATH:/new/path",
        NULL
    };

    int i = 0;
    while (inputs[i] != NULL)
    {
        test_tokenize_input(inputs[i]);
        i++;
    }

    return 0;
}
