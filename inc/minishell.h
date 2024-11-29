#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

typedef enum e_token_type{
    WORD,       // general words
    PIPE,       // |
    REDIR_IN,   // <
    REDIR_OUT,  // >
    APPEND,     // >>
    HEREDOC,    // <<
    VARIABLE,   // $var
    OTHER       // other special caracters
}       t_token_type;

typedef struct s_token{
    char            *value;     // token content
    t_token_type    type;       // token type
    struct s_token  *next;      // next token of the list
}       t_token;

//? src
void test_tokenize_input(const char *input);
const char *process_redirection(const char *input, t_token **head, t_token **current);
t_token *create_token(const char *value, t_token_type type);
void add_token(t_token **head, t_token **current, t_token *new_token);
void print_tokens(t_token *tokens);
t_token *tokenize_input(const char *input);
const char *skip_spaces(const char *input);

//? src/env
const char *process_variable(const char *input, t_token **head, t_token **current);

//? src/parse
const char *process_other(const char *input, t_token **head, t_token **current);
const char *process_word(const char *input, t_token **head, t_token **current);
const char *process_pipe(const char *input, t_token **head, t_token **current);
const char *process_redirection(const char *input, t_token **head, t_token **current);
const char *handle_output_redirection(const char *input, t_token **new_token);
const char *handle_input_redirection(const char *input, t_token **new_token);
const char *process_variable(const char *input, t_token **head, t_token **current);


#endif