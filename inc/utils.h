#ifndef ERROR_H
# define ERROR_H
# include "../minishell.h"

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                     〘LEXER〙

//? minishell_prompt.c
char *create_prompt(void);
int check_exit(t_data *data);

//? cleanup.c
void cleanup_data(t_data *data);
void free_pipeline(t_pipeline *pipeline);

//? parser_errors.c
int handle_tokenization_error(void);
int handle_syntax_error(void);

//? error.c
void	errmsg(char *errmsg, char *detail, int quotes);
void	free_ptr(void *ptr);

//? enviroment_utils.c
void init_environment(t_data *data);

//? validate.c
int validate_tokens(t_token *tokens);

#endif