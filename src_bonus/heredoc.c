/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:48:24 by aneri-da          #+#    #+#             */
/*   Updated: 2025/02/06 19:41:31 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	heredoc_message(int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
		ft_printf("pipe ");
	ft_printf("heredoc> ");
}

static void	read_file(int temp_file, int *pid_fd)
{
	int		file_read;
	int		line_length;
	char	*line;

	close(temp_file);
	file_read = open("heredoc", O_RDONLY);
	line = get_next_line(file_read);
	while (line != NULL)
	{
		line_length = ft_strlen(line);
		write(pid_fd[1], line, line_length);
		free(line);
		line = NULL;
		line = get_next_line(file_read);
	}
	close(file_read);
	close(pid_fd[1]);
	if (unlink("heredoc") != '\0')
	{
		perror("Error deleting temporary file!");
		exit(1);
	}
	exit(0);
}

static void	put_heredoc(int ac, char **av, int *pid_fd)
{
	char	*line;
	int		delimeter_length;
	int		line_length;
	int		temp_file;

	close(pid_fd[0]);
	temp_file = open("heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	delimeter_length = ft_strlen(av[2]);
	while (1)
	{
		heredoc_message(ac);
		line = get_next_line(0);
		if (!line)
			break ;
		line_length = ft_strlen(line);
		if (ft_strncmp(line, av[2], delimeter_length) == 0)
		{
			free(line);
			break ;
		}
		write(temp_file, line, line_length);
		free(line);
	}
	read_file(temp_file, pid_fd);
}

void	heredoc(int ac, char **av)
{
	int		pid_fd[2];
	pid_t	pid;

	if (pipe(pid_fd) < 0)
		exit(0);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (!pid)
		put_heredoc(ac, av, pid_fd);
	else
	{
		close(pid_fd[1]);
		dup2(pid_fd[0], STDIN_FILENO);
		close(pid_fd[0]);
	}
	wait(NULL);
}
