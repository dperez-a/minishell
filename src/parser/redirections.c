#include "../../minishell.h"

t_token *handle_redirection(t_token *token, t_command *command)
{
    if (token->type == INPUT && token->next && token->next->type == WORD)
    {
        command->input_file = ft_strdup(token->next->str);
        command->input_redir_type = INPUT;
        return token->next;
    }
    else if (token->type == TRUNC && token->next && token->next->type == WORD)
    {
        command->output_file = ft_strdup(token->next->str);
        command->output_redir_type = TRUNC;
        return token->next;
    }
    else if (token->type == APPEND && token->next && token->next->type == WORD)
    {
        command->output_file = ft_strdup(token->next->str);
        command->output_redir_type = APPEND;
        return token->next;
    }
    else if (token->type == HEREDOC && token->next && token->next->type == WORD)
    {
        command->output_file = ft_strdup(token->next->str);
        command->output_redir_type = HEREDOC;
        return token->next;
    }
    return token;
}
int process_redirections(t_token *tokens)
{
    t_token *current = tokens;

    while (current)
    {
        // Si el token actual es una redirección...
        if (current->type == TRUNC || current->type == APPEND ||
            current->type == INPUT || current->type == HEREDOC)
        {
            // Caso 1: Redirección sin archivo después
            if (!current->next || current->next->type != WORD)
            {
                printf("Error: Redirección '%s' sin un archivo válido.\n", current->str);
                return (1);
            }

            // Caso 2: Redirecciones consecutivas sin un archivo intermedio
            if (current->next && (current->next->type == TRUNC ||
                                  current->next->type == APPEND ||
                                  current->next->type == INPUT ||
                                  current->next->type == HEREDOC))
            {
                printf("Error: Redirecciones consecutivas sin archivo intermedio.\n");
                return (1);
            }
        }
        current = current->next;
    }
    return (0);
}