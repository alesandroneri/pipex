#include "includes/pipex_bonus.h"

char	*get_path(char *cmd, char **ep)
{
	char	*path;
	char	**dirs;
	char	*partial_path;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	i = -1;
	while (ep[++i] != NULL)
		if (ft_strncmp(ep[i], "PATH=", 5) == 0)
			break ;
	dirs = ft_split(ep[i] + 5, ':');
	if (!dirs)
		return (NULL);
	i = -1;
	while (dirs[++i] != NULL)
	{
		partial_path = ft_strjoin(dirs[i], "/");
		path = ft_strjoin(partial_path, cmd);
		free(partial_path);
		if (access(path, X_OK | F_OK) == 0)
			return (path);
		free(path);
	}
	free_split(dirs);
	return (0);
}

void	execute(char *av, char **ep)
{
	char	**cmd;
	char	**args;
	char	*path;
	int		arg_count;
	t_parse	st;

	init_variables(&st);
	arg_count = count_args(av);
	args = (char **)malloc(sizeof(char *) * (arg_count + 1));
	cmd = parse_args(args, av, st);
	if (!cmd)
		exit(1);
	path = get_path(cmd[0], ep);
	if (!path)
	{
		free_split(cmd);
		perror("get_path");
		exit(127);
	}
	if (execve(path, cmd, ep) < 0)
	{
		free_split(cmd);
		perror("execve");
		exit(127);
	}
}
void heredoc_message(char *str)
{
	
}

void	put_heredoc(char **av, int *pid_fd)
{
	char	*line;
	char	*delimeter;
	int		delimeter_length;
	int		line_length;
	int		temp_file;

	close(pid_fd[0]);
	temp_file = open("heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	delimeter = av[2];
	delimeter_length = ft_strlen(av[2]);
	while (1)
	{
		ft_printf("heredoc> ");
		line = get_next_line(0);
		line_length = ft_strlen(line);
		write(temp_file, line, line_length);
		if (!line)
			break ;
		if (ft_strncmp(line, delimeter, delimeter_length) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, pid_fd[1]);
		free(line);
	}
	unlink("heredoc");
	close(pid_fd[1]);
	exit(0);
}

void	heredoc(char **av)
{
	int		pid_fd[2];
	pid_t	pid;

	if (pipe(pid_fd) < 0)
		exit(0);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (!pid)
		put_heredoc(av, pid_fd);
	else
	{
		close(pid_fd[1]);
		dup2(pid_fd[0], STDIN_FILENO);
		close(pid_fd[0]);
	}
	wait(NULL);
}

void	process(char *cmd, char **ep, int last, int fd_output)
{
	int		pid_fd[2];
	pid_t	pid;

	if (!last && pipe(pid_fd) < 0)
		exit(0);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (!pid)
	{
		if (!last)
		{
			close(pid_fd[0]);
			dup2(pid_fd[1], STDOUT_FILENO);
			close(pid_fd[1]);
		}
		else
		{
			dup2(fd_output, STDOUT_FILENO);
			close(fd_output);
		}
		execute(cmd, ep);
	}
	if (!last)
	{
		close(pid_fd[1]);
		dup2(pid_fd[0], STDIN_FILENO);
		close(pid_fd[0]);
	}
	wait(NULL);
}

int	main(int ac, char **av, char **ep)
{
	int	i;
	int	last;
	int	fd_input;
	int	fd_output;

	if (ac < 5)
		exit(0);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 2;
		fd_output = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		heredoc(av);
		fd_input = open("heredoc", O_RDONLY);
	}
	i = 1;
	fd_input = open(av[1], O_RDONLY);
	fd_output = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	while (++i <= (ac - 2))
	{
		last = (i == ac - 2);
		process(av[i], ep, last, fd_output);
	}
	return (0);
}
