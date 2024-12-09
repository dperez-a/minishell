#include "../../minishell.h"

//? input redirections
t_token *process_input_redirection(t_token *token, t_command *command)
{
    if (!token)
        return NULL;  // Verificar que token no sea NULL

    token = token->next;  // Avanzar al siguiente token
    if (token && token->type == WORD)
    {
        if (token->value)
        {
            command->input_file = ft_strdup(token->value);
            if (!command->input_file)
            {
                printf("Error: Fallo al duplicar el valor del token.\n");
                return NULL;
            }
        }
        command->input_redir_type = REDIR_IN;
    }
    return token ? token->next : NULL;  // Devolver el siguiente token
}

//? output redirections
t_token *process_output_redirection(t_token *token, t_command *command)
{
    if (!token)
        return NULL;

    token = token->next;
    if (token && token->type == WORD)
    {
        if (token->value)
        {
            command->output_file = ft_strdup(token->value);
            if (!command->output_file)
            {
                printf("Error: Fallo al duplicar el valor del token.\n");
                return NULL;
            }
        }
        command->output_redir_type = REDIR_OUT;
    }
    return token ? token->next : NULL;
}

//? append redirections
t_token *process_append_redirection(t_token *token, t_command *command)
{
    if (!token)
        return NULL;

    token = token->next;
    if (token && token->type == WORD)
    {
        if (token->value)
        {
            command->output_file = ft_strdup(token->value);
            if (!command->output_file)
            {
                printf("Error: Fallo al duplicar el valor del token.\n");
                return NULL;
            }
        }
        command->output_redir_type = APPEND;
    }
    return token ? token->next : NULL;
}

//? heredoc redirections
t_token *process_heredoc_redirection(t_token *token, t_command *command)
{
    if (!token)
        return NULL;

    token = token->next;
    if (token && token->type == WORD)
    {
        if (token->value)
        {
            command->output_file = ft_strdup(token->value);
            if (!command->output_file)
            {
                printf("Error: Fallo al duplicar el valor del token.\n");
                return NULL;
            }
        }
        command->output_redir_type = HEREDOC;
    }
    return token ? token->next : NULL;
}
