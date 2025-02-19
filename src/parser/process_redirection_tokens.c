#include "../../minishell.h"

static t_command *init_command(void)
{
    t_command *command = ft_calloc(1, sizeof(t_command));
    if (!command)
        return NULL;

    // Inicializar los valores de la estructura
    command->command = NULL;
    command->args = NULL;
    command->input_file = NULL;
    command->output_file = NULL;
    command->input_redir_type = 0;
    command->output_redir_type = 0;

    return command;
}

// Agrega un argumento a la lista de argumentos del comando
static void add_argument(t_command *command, char *arg, int *arg_count)
{
    command->args = ft_realloc(command->args, sizeof(char *) * (*arg_count + 2));
    command->args[*arg_count] = ft_strdup(arg);
    (*arg_count)++;
    command->args[*arg_count] = NULL; // Asegurar terminación en NULL
}

// Procesa los tokens para extraer el comando y sus argumentos
static void process_tokens(t_token *tokens, t_command *command)
{
    int arg_count = 0;

    while (tokens)
    {
        if (tokens->type == PIPE)
            break;  // ❗ Si encontramos un PIPE, terminamos la función ❗

        if (tokens->type == WORD)
        {
            if (!command->command)
                command->command = ft_strdup(tokens->str);
            add_argument(command, tokens->str, &arg_count);
        }
        else if (tokens->type == INPUT || tokens->type == TRUNC ||
                 tokens->type == APPEND || tokens->type == HEREDOC)
        {
            tokens = handle_redirection(tokens, command);
            if (!tokens)
                break;
            continue;
        }
        tokens = tokens->next;
    }
}

// Función principal que gestiona el procesamiento de redirecciones
t_command *process_redirection_tokens(t_token **tokens)
{
    t_command *command = init_command();
    if (!command)
        return NULL;

    process_tokens(*tokens, command);
    return command;
}
