#ifndef ERROR_H
# define ERROR_H
# include "../minishell.h"

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                     〘LEXER〙

//? error.c
void	errmsg(char *errmsg, char *detail, int quotes);
void	free_ptr(void *ptr);

//? enviroment_utils.c
void init_environment(t_data *data);

#endif