#ifndef DEBUG_H
# define DEBUG_H
# include "../minishell.h"

void	print_token_type(t_token *token, char *prefix);
void	print_token_list(t_token **tokens);

#endif