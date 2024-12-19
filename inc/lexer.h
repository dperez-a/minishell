#ifndef LEXER_H
# define LEXER_H
# include "../minishell.h"
// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                     〘LEXER〙

//? tokenizer.c
int     tokenization(t_data *data, char *str);
void    remove_end_token(t_data *data);
void    handle_unexpected_eof(int status);

//? token_utils.c
int     save_separator(t_token **token_lst, char *str, int index, int type);
int     save_word(t_token **token_lst, char *str, int index, int start);
int     is_separator(char *str, int i);
int     set_status(int status, char *str, int i);
int     save_word_or_sep(int *i, char *str, int start, t_data *data);

//? token_lst_utils.c
t_token *lst_new_token(char *str, char *str_backup, int type, int status);
void	lst_add_back_token(t_token **alst, t_token *new_node);
void	lstdelone_token(t_token *lst, void (*del)(void *));
void	lstclear_token(t_token **lst, void (*del)(void *));

//? token_lst_utils_2.c
// static void	link_extremities(t_token *to_del, t_token *temp, t_token *insert);
t_token *insert_lst_between(t_token **head, t_token *to_del, t_token *insert);

#endif