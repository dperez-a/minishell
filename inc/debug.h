#ifndef DEBUG_H
# define DEBUG_H
# include "../minishell.h"

//? token_deb.c
void	print_token_type(t_token *token, char *prefix);
void	print_token_list(t_token **tokens);

//? pipe_deb.c
void    print_pipeline(t_pipeline *pipeline);

#endif