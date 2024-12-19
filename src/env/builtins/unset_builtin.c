#include "../../../minishell.h"

void unset_builtin(t_env_var **env_vars, const char *key)
{
    t_env_var *current = *env_vars;
    t_env_var *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev)
                prev->next = current->next;
            else
                *env_vars = current->next;

            free(current->key);
            free(current->value);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
