#ifndef PARSER_H
# define PARSER_H
# include "../minishell.h"
// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                      {PARSER}

//? pipes.c
t_token     **split_by_pipes(t_token *tokens, int *num_pipes);
t_pipeline  *process_pipeline(t_token *tokens);

//? redirections.c
t_command   *process_redirection_tokens(t_token **tokens);
t_token     *handle_redirection(t_token *token, t_command *command);

#endif