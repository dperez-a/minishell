#include "../../include/path.h"

char **ft_create_path(char **env)
{
	char	**path;
	int		i;

	i = -1;
	path = NULL;
	while (env[++i] != NULL)
	{
		if (ft_strnstrstr(env[i], "PATH=", 5))
			path = ft_split(env[i] + 5, ':');
	}
	return (path);
}

static char	*ft_father(int *fd, char *search)
{
	char	*line;

	close(fd[1]);
	line = get_next_line(fd[0]);
	while (line != NULL)
	{
		if (ft_strnstr(line, search, ft_strlen(search)) != NULL)
		{
			close(fd[0]);
			return(line);
		}
		free(line);
		line = get_next_line(fd[0]);
	}
	return(NULL);
}

static void	ft_pid_0(int *fd, char *path, char **file, char **env)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(path, file, env);
	ft_strstr_free(file);
	free(path);
	perror("execve");
	exit(1);
}

char	*ft_execute(char **env, char **file, char *path, char *search)
{
	char	*line;
	int		fd[2];
	pid_t	pid;

	if(access(path, X_OK) == -1)
		return (NULL);
	if (pipe(fd) == -1)
		return (NULL);
	pid = fork();
	if(pid == -1)
		return(NULL);
	if(pid == 0)
		ft_pid_0(fd, path, file, env);
	else
		line= ft_father(fd,search);
	return (line);
}

char	**ft_save_path(char	**env)
{
	char	**path;
	char	**file;
	char	*line;
	char	*trim;

	file = ft_sindub_join(NULL, "systemd-path");
	line = ft_execute(env, file,
			"/usr/bin/systemd-path", "search-binaries-default:");
	ft_strstr_free(file);
	trim = ft_strtrim(line, "\n");
	if (trim == NULL)
		return (NULL);
	free(line);
	path = ft_split(trim + ft_strlen("search-binaries-default: "), ':');
	free(trim);
	return (path);
}
