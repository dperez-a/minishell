#ifndef ENV_H
# define ENV_H
# include "../minishell.h"

//? env.c
// char        *get_user_input(void);
// void        process_user_input(t_data *data);
void        interactive_shell(void);

//? env_vars_init.c
t_env_var   *create_env_var(const char *env_str);
void        initialize_env(t_data *data, char **envp);

//? env_builtin.c
void        env_builtin(t_env_var *env_vars);

//? export_builtin.c
void        export_builtin(t_env_var **env_vars, const char *key, const char *value);

//? unset_builtin.c
void        unset_builtin(t_env_var **env_vars, const char *key);
#endif