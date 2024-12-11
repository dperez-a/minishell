#include "../../minishell.h"

void handle_unexpected_eof(int status)
{
    if (status == DQUOTE)
        errmsg("unexpected EOF while looking for matching", "\"", 1);
    else if (status == SQUOTE)
        errmsg("unexpected EOF while looking for matching", "\'", 1);
    errmsg("syntax error", "unexpected end of file", 0);
}

int tokenization(t_data *data, char *str)
{
    int i;
    int end;
    int start;
    int status;

    i = -1;
    start = 0;
    end = ft_strlen(str);
    status = DEFAULT;
    while (++i <= end)
    {
        status = set_status(status, str, i);
        if (status == DEFAULT)
            start = save_word_or_sep(&i, str, start, data);
    }
    if (status != DEFAULT)
    {
        handle_unexpected_eof(status);
        return (1);
    }
    remove_end_token(data);
    return (0);
}

void remove_end_token(t_data *data)
{
    t_token *last_token = data->token;

    // Encuentra el último token
    while (last_token && last_token->next)
        last_token = last_token->next;

    // Si el último token es de tipo END, elimínalo
    if (last_token && last_token->type == END)
    {
        if (last_token->prev)
            last_token->prev->next = NULL;
        else
            data->token = NULL; // Si es el único token, actualiza el puntero de la lista

        free(last_token->str);
        free(last_token);
    }
}
