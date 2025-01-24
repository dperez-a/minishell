#include "../../minishell.h"

//* clear the asociated memory to t_data
void cleanup_data(t_data *data)
{
    lstclear_token(&data->token, free);
    free(data->user_input);
}

void free_pipeline(t_pipeline *pipeline)
{
    if (!pipeline)
        return;

    if (pipeline->commands)
    {
        int i = 0;
        while (i < pipeline->count)
        {
            if (pipeline->commands[i])
            {
                // Liberar memoria de cada comando
                free(pipeline->commands[i]->command);
                free(pipeline->commands[i]->input_file);
                free(pipeline->commands[i]->output_file);
                free(pipeline->commands[i]);
            }
            i++;
        }
        free(pipeline->commands);
    }
    free(pipeline);
}
