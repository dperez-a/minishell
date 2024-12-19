#include "../../minishell.h"

t_env_var *create_env_var(const char *env_str)
{
    t_env_var *var = malloc(sizeof(t_env_var));
    if (!var)
        return NULL;

    char *equal_sign = strchr(env_str, '=');
    if (equal_sign)
    {
        var->key = strndup(env_str, equal_sign - env_str);
        var->value = strdup(equal_sign + 1);
    }
    else
    {
        var->key = strdup(env_str);
        var->value = NULL;
    }
    var->next = NULL;
    return var;
}

void initialize_env(t_data *data, char **envp)
{
    t_env_var **current = &data->env_vars;

    while (*envp)
    {
        *current = create_env_var(*envp);
        current = &(*current)->next;
        envp++;
    }
}
