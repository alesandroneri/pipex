/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:15:03 by aneri-da          #+#    #+#             */
/*   Updated: 2025/02/03 17:41:20 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	count_args(const char *input)
{
	int		i;
	int		count;
	char	quote_char;

	i = 0;
	count = 0;
	quote_char = 0;
	while (input[i])
	{
		while (input[i++] == ' ')
			if (!input[i])
				break ;
		count++;
		if (input[i] == '\'' || input[i] == '\"')
		{
			quote_char = input[i++];
			while (input[i] && input[i++] != quote_char)
				if (input[i])
					i++;
		}
		while (input[i] && input[i] != ' ' && input[i] != '\''
			&& input[i] != '\"')
			i++;
	}
	return (count);
}

void	trimming_args(char **args, int arg_count)
{
	int		i;
	char	*trimmed;

	i = -1;
	while (++i < arg_count)
	{
		trimmed = ft_strtrim(args[i], "\"'");
		free(args[i]);
		args[i] = trimmed;
	}
}

void	init_variables(t_parse *st)
{
	st->i = 0;
	st->j = 0;
	st->start = 0;
	st->in_quotes = 0;
	st->quote_char = 0;
}

char	**parse_args(char **args, char *input, t_parse st)
{
	while (input[++st.i])
	{
		if ((input[st.i] == '\'' || input[st.i] == '\"') && !st.in_quotes)
		{
			st.in_quotes = 1;
			st.quote_char = input[st.i];
			st.start = st.i + 1;
		}
		else if (input[st.i] == st.quote_char && st.in_quotes)
		{
			st.in_quotes = 0;
			args[st.j++] = ft_strndup(&input[st.start], st.i - st.start);
			st.start = st.i + 1;
		}
		else if (input[st.i] == ' ' && !st.in_quotes)
		{
			args[st.j++] = ft_strndup(&input[st.start], st.i - st.start);
			st.start = st.i + 1;
		}
	}
	if (st.i > st.start)
		args[st.j++] = ft_strndup(&input[st.start], st.i - st.start);
	args[st.j] = NULL;
	trimming_args(args, st.j);
	return (args);
}
