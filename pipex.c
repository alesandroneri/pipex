/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:50:42 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/29 16:08:32 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void exec(t_list **cmd, char **ep)
{
    if (execve(COMMAND_PATH, ))
}

void child_process(char **input_file, int *pid_fd, char **ep)
{
    int fd;
    fd = open(input_file[1], 0);
    dup2(fd, 0);
    dup2(pid_fd[1], STDOUT_FILENO);
    close(pid_fd[1]);
}
void parent_process(char **output_file, int *pid_fd, char **ep)
{
    int fd;
    fd = open(output_file[4], 1);
    dup2(fd, 1);
    dup2(pid_fd[0], STDIN_FILENO);
    close(pid_fd[0]);

}

int main(int ac, char **av, char **ep)
{
    int fd[2];
    pid_t pid;
    t_list *cmd;
    int i;

    if (ac != 5)
    {
        ft_putendl_fd("Invalid number of arguments.", 2);
        return (0);
    }
    if(pipe(fd) < 0)
    {
        perror("pipe");
        return (0);
    }
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return (0);
    }
    i = 1;
    while (++i < (ac - 2))
        ft_lstadd_back(&cmd, av[i]);
    return (1);
}