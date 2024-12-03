#ifndef REDIRECT_H
# define REDIRECT_H
# include "../minishell.h"
// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘REDIRECT〙

//? src/redirect
t_command   *process_redirection_tokens(t_token **tokens);
t_token     *process_redirection_types(t_token *tokens, t_command *command);

//?redir_types.c
t_token     *process_input_redirection(t_token *token, t_command *command);
t_token     *process_output_redirection(t_token *token, t_command *command);
t_token     *process_append_redirection(t_token *token, t_command *command);
t_token     *process_heredoc_redirection(t_token *token, t_command *command);

const char  *handle_output_redirection(const char *input, t_token **new_token);
const char  *handle_input_redirection(const char *input, t_token **new_token);

#endif