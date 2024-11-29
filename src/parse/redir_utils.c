#include "../../inc/minishell.h"

const char *handle_output_redirection(const char *input, t_token **new_token)
{
    if (input[1] == '>')
    {
        *new_token = create_token(">>", APPEND);
        input += 2;  // to advance two characters
    } 
    else
    {
        *new_token = create_token(">", REDIR_OUT);
        input++;  // to only advance one
    }
    return input;
}

const char *handle_input_redirection(const char *input, t_token **new_token)
{
    if (input[1] == '<')
    {
        *new_token = create_token("<<", HEREDOC);
        input += 2;  // to advance two characters
    } 
    else
    {
        *new_token = create_token("<", REDIR_IN);
        input++;  // to advance only one
    }
    return input;
}
