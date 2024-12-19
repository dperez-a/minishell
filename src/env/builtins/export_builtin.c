#include "../../../minishell.h"

void export_builtin(t_env_var **env_vars, const char *key, const char *value)
{
    t_env_var *current = *env_vars;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            return;
        }
        current = current->next;
    }
    t_env_var *new_var = malloc(sizeof(t_env_var));
    new_var->key = strdup(key);
    new_var->value = strdup(value);
    new_var->next = *env_vars;
    *env_vars = new_var;
}
