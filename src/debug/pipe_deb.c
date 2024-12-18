#include "../../minishell.h"

void print_pipeline(t_pipeline *pipeline)
{
	int i;

	printf("\nPipeline con %d comandos:\n", pipeline->count);

	i = 0;
	while (i < pipeline->count)
	{
		t_command *cmd = pipeline->commands[i];
		printf("Comando %d: %s\n", i + 1, cmd->command);

		if (cmd->input_file != NULL)
			printf("  Archivo entrada: %s\n", cmd->input_file);
        else
            printf("  Archivo entrada: None\n");

        if (cmd->output_file != NULL)
            printf("  Archivo salida: %s\n", cmd->output_file);
        else
            printf("  Archivo salida: None\n");

        printf("  Tipo redirección entrada: %d\n", cmd->input_redir_type);
        printf("  Tipo redirección salida: %d\n", cmd->output_redir_type);
        i++;
    }
}

