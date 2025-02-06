/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:52:05 by aneri-da          #+#    #+#             */
/*   Updated: 2025/02/06 19:49:16 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_parse
{
	int		in_quotes;
	char	quote_char;
	int		i;
	int		j;
	int		start;
}			t_parse;

void		heredoc(int ac, char **av);
void		init_variables(t_parse *st);
int			count_args(const char *input);
char		**parse_args(char **args, char *input, t_parse st);
void		open_heredoc_fd(int ac, char **av, int fd_input, int fd_output);
void		open_fd(int ac, char **av, int fd_input, int fd_output);

#endif
