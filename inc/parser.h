#ifndef PARSER_H
# define PARSER_H
# include "../minishell.h"
// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                      {PARSER}

//? pipes.c
t_token     **split_by_pipes(t_token *tokens, int *num_pipes);
t_pipeline  *process_pipeline(t_token *tokens, int num_pipes);
t_command   *process_segments(t_token *tokens);
void print_pipeline(t_pipeline *pipeline);//!se puede borrar, es una función de prueba

//? process_redirection_tokens.c
t_command *process_redirection_tokens(t_token **tokens);

//? redirections.c
t_token *handle_redirection(t_token *token, t_command *command);
int process_redirections(t_token *tokens);

//?extract_args.c
char **extract_arguments(t_token *tokens);
#endif