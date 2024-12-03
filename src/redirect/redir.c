#include "../../minishell.h"

t_command *process_redirection_tokens(t_token **tokens)
{
    t_command *command = ft_calloc(1, sizeof(t_command));
    if (!command)
        return NULL;
    // Inicialización de campos a valores predeterminados
    command->command = NULL;
    command->input_file = NULL;
    command->output_file = NULL;
    command->input_redir_type = 0;
    command->output_redir_type = 0;

    // Buscar el primer token que sea un comando
    while (*tokens && (*tokens)->type != WORD)
    {
        *tokens = (*tokens)->next;
    }

    if (*tokens && (*tokens)->type == WORD)
    {
        command->command = ft_strdup((*tokens)->value);
        if (!command->command)
        {
            free(command);
            return NULL;
        }
        *tokens = (*tokens)->next;  // Avanzar al siguiente token
    }
    else
    {
        printf("Error: No se encontró un comando válido.\n");
        free(command);
        return NULL;
    }

    // Procesar las redirecciones
    while (*tokens && ((*tokens)->type == REDIR_IN || (*tokens)->type == REDIR_OUT ||
                       (*tokens)->type == APPEND || (*tokens)->type == HEREDOC))
    {
        *tokens = process_redirection_types(*tokens, command);
    }
    return command;
}

t_token *process_redirection_types(t_token *tokens, t_command *command)
{
    if (tokens->type == REDIR_IN)
    {
        tokens = process_input_redirection(tokens, command);
    }
    else if (tokens->type == REDIR_OUT)
    {
        tokens = process_output_redirection(tokens, command);
    }
    else if (tokens->type == APPEND)
    {
        tokens = process_append_redirection(tokens, command);
    }
    else if (tokens->type == HEREDOC)
    {
        tokens = process_heredoc_redirection(tokens, command);
    }
    return tokens;
}