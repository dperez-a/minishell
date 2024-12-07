#include "../../minishell.h"

//? create a new token
t_token *create_token(const char *value, t_token_type type)
{
    t_token *token = ft_calloc(1, sizeof(t_token));
    if (!token)
        return NULL;
    token->value = strdup(value);  // copy the value
    token->type = type;
    token->next = NULL;
    return token;
}

//? to add a token to the token list
void add_token(t_token **head, t_token **current, t_token *new_token)
{
    if (*head == NULL) {
        *head = new_token;
    } else {
        (*current)->next = new_token;
    }
    *current = new_token;
}

void print_tokens(t_token *tokens)
{
    while (tokens) {
        printf("Token: '%s', Type: %d\n", tokens->value, tokens->type);
        tokens = tokens->next;
    }
}
