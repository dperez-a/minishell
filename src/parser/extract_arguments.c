#include "../../minishell.h"

char **extract_arguments(t_token *tokens)
{
    int count = 0;
    t_token *tmp = tokens;

    //count args quantity
    while(tmp && tmp->type != PIPE)
    {
        if (tmp->type == WORD)
            count++;
        tmp = tmp->next;
    }

    //reserv memory for args +NULL at the end
    char **args = ft_calloc(count + 1, sizeof(char *));
    if (!args)
    return NULL;

    //complete args with token values
    tmp = tokens;
    int i = 0;
    while (tmp && tmp->type != PIPE)
    {
        if (tmp->type == WORD)
            args[++i] = ft_strdup(tmp->str);
        tmp = tmp->next;
    }

    args[i] = NULL; // the end of args list
    return args;
}
