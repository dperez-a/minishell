#include "../../../minishell.h"

void env_builtin(t_env_var *env_vars)
{
    while (env_vars)
    {
        if (env_vars->value)
            printf("%s=%s\n", env_vars->key, env_vars->value);
        else
            printf("%s\n", env_vars->key);
        env_vars = env_vars->next;
    }
}
