/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:32:08 by aneri-da          #+#    #+#             */
/*   Updated: 2025/02/06 19:41:29 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	part_process(int *pid_fd, int last)
{
	if (!last)
	{
		close(pid_fd[0]);
		dup2(pid_fd[1], STDOUT_FILENO);
		close(pid_fd[1]);
	}
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
		part_process(pid_fd, last);
		if (last)
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
	int	fd_input;
	int	fd_output;

	if (ac > 4 && ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 2;
		heredoc((ac - 5), av);
		fd_input = open("heredoc", O_RDONLY);
		fd_output = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	if (ac > 4 && ft_strcmp(av[1], "here_doc") != 0)
	{
		i = 1;
		fd_input = open(av[1], O_RDONLY);
		fd_output = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd_input, STDIN_FILENO);
		close(fd_input);
	}
	while (++i <= (ac - 2))
		process(av[i], ep, (i == ac - 2), fd_output);
	return (0);
}
