#include "../../minishell.h"

//? input redirections
t_token *process_input_redirection(t_token *token, t_command *command)
{
    token = token->next;  // Avanzamos al siguiente token
    if (token && token->type == WORD)
    {
        command->input_file = ft_strdup(token->value);
        command->input_redir_type = REDIR_IN;
    }
    return token ? token->next : NULL;  // Ahora devolvemos el siguiente token, no una cadena de caracteres
}

//? output redirections
t_token *process_output_redirection(t_token *token, t_command *command)
{
    token = token->next;  // Avanzar al siguiente token
    if (token && token->type == WORD)
    {
        command->output_file = ft_strdup(token->value);
        command->output_redir_type = REDIR_OUT;
    }
    return token ? token->next : NULL;  // Ahora devolvemos el siguiente token, no una cadena de caracteres
}

//? append redirections
t_token *process_append_redirection(t_token *token, t_command *command)
{
    token = token->next;  // Avanzamos al siguiente token
    if (token && token->type == WORD)
    {
        command->output_file = ft_strdup(token->value);
        command->output_redir_type = APPEND;
    }
    return token ? token->next : NULL;  // Ahora devolvemos el siguiente token, no una cadena de caracteres
}

//? heredoc redirections
t_token *process_heredoc_redirection(t_token *token, t_command *command)
{
    token = token->next;  // Avanzamos al siguiente token
    if (token && token->type == WORD)
    {
        command->output_file = ft_strdup(token->value);
        command->output_redir_type = HEREDOC;
    }
    return token ? token->next : NULL;  // Ahora devolvemos el siguiente token, no una cadena de caracteres
}