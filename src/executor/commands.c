#include "../../minishell.h"

void    ft_pid_fork_error(pid_t pid)
{
    if (pid < 0)
        ft_exit_msg("Error\n\t• Fork cannot duplicate process", 1);
}

void	ft_exit_msg(char *msg, int errorvalue)
{
	if (errorvalue >= 0)
		perror(msg);
	else
		ft_printf("%s", msg);
	write(2, "\n", 1);
	exit (errorvalue);
}

void    command_execute(t_command *command)
{
    int     status;
    pid_t   pid;
    int     fd_in;
    int     fd_out;

    pid = fork();
// son process
    if (pid == 0)
    {
        if (command->input_file)
        {
            fd_in = open(command->input_file, O_RDONLY);
            dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }
        if (command->output_file)
        {
            fd_out = open(command->output_file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }
        char *argv[] = (command->command, NULL);
        execvp(command->command, argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
// father process
    else
        waitpid(pid, &status, 0);
}
