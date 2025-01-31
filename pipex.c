/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:50:42 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/31 19:48:37 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

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
	char	*path;

	cmd = ft_split(av, ' ');
	if (!cmd)
		exit(1);
	path = get_path(cmd[0], ep);
	if (!path)
	{
		free_split(cmd);
		perror("get_path");
		exit(127);
	}
	if (execv(path, cmd) < 0)
	{
		free_split(cmd);
		perror("execv");
		exit(127);
	}
}

void	child_process(char **av, int *pid_fd, char **ep)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open input file");
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pid_fd[1], STDOUT_FILENO);
	close(pid_fd[0]);
	close(pid_fd[1]);
	execute(av[2], ep);
}

void	parent_process(char **av, int *pid_fd, char **ep)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open output file");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(pid_fd[0], STDIN_FILENO);
	close(pid_fd[1]);
	execute(av[3], ep);
}

int	main(int ac, char **av, char **ep)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
		{
			perror("pipe");
			return (-1);
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return (-1);
		}
		if (pid == 0)
			child_process(av, fd, ep);
		close(fd[1]);
		parent_process(av, fd, ep);
		return (0);
	}
	ft_putendl_fd("Error: invalid number of arguments.", 2);
	return (1);
}
