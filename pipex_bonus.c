#include "includes/pipex_bonus.h"

char	*get_path(char *cmd, char **ep)
{
	char	*path;
	char	**dirs;
	char	*partial_path;
	int		i;

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
		if (access(path, X_OK) == 0)
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
	if (execve(path, cmd, NULL) < 0)
	{
		free_split(cmd);
		perror("execve");
		exit(127);
	}
}

void put_heredoc(char **av, int *pid_fd)
{
	char *line;

	close(pid_fd[0]);
	ft_printf("heredoc> ");
	line = get_next_line(0);
	while (line != NULL)
	{
		//ft_printf("heredoc> ");
		//line = get_next_line(0);
		//if (!line)
		//	break ;
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, pid_fd[1]);
		free(line);
		line = get_next_line(0);
		ft_printf("heredoc> ");
	}
	close(pid_fd[1]);
	exit(0);
}

void heredoc(char **av)
{
	int pid_fd[2];
	pid_t pid;

	if(pipe(pid_fd) < 0)
		exit(0);
	pid = fork();
	if(pid < 0)
		exit(0);
	if(!pid)
		put_heredoc(av, pid_fd);
	else
	{
		close(pid_fd[1]);
		dup2(pid_fd[0], STDIN_FILENO);
		close(pid_fd[0]);
		wait(NULL);
	}
}

void handle_pipe_fork(char *cmd, char **ep)
{
    int pid_fd[2];
    pid_t pid;

    if(pipe(pid_fd) < 0)
        exit(0);
    pid = fork();
    if (pid < 0)
        exit(0);
    if (!pid)
    {
        close(pid_fd[0]);
        dup2(pid_fd[1], STDOUT_FILENO);
		close(pid_fd[1]);
        execute(cmd, ep);
    }
    else
    {
        close(pid_fd[1]);
        dup2(pid_fd[0], STDIN_FILENO);
		close(pid_fd[0]);
		wait(NULL);
    }
}

int	main(int ac, char **av, char **ep)
{
	int i;
    int fd_input;
    int fd_output;

    if (ac < 5)
        exit(1);
    if (ft_strcmp(av[1], "here_doc") == 0)
    {
        i = 3;
		fd_output = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		heredoc(av);
    }
    i = 2;
    fd_input = open_fd(av[1], 0);
	fd_output = open_fd(av[ac - 1], 1);
    dup2(fd_input, 0);
	close(fd_input);
    while (i < (ac - 2))
	{
        handle_pipe_fork(av[i++], ep);
	}
	return (0);
}
