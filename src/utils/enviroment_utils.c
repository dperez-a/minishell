#include "../../minishell.h"

void init_environment(t_data *data)
{
    // Inicializar el entorno
    data->interactive = true;
    data->token = NULL;
    data->user_input = NULL;
    data->env = getenv("PATH"); // Ejemplo de inicialización de variables de entorno
    data->working_dir = getcwd(NULL, 0);
    data->old_working_dir = NULL;
    data->cmd = NULL;
    data->env_vars = NULL;
    data->pid = getpid();
}
