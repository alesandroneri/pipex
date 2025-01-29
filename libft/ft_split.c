/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:39:22 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/08 19:27:29 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *str, char sep)
{
	int	count;
	int	word;
	int	i;

	count = 0;
	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep && word == 0)
		{
			count++;
			word = 1;
		}
		else if (str[i] == sep)
			word = 0;
		i++;
	}
	return (count);
}

static int	safe_malloc(char **strs, int pos, int buffer)
{
	int	i;

	i = 0;
	strs[pos] = (char *)malloc(sizeof(char) * buffer);
	if (strs[pos] == NULL)
	{
		while (i < pos)
			free(strs[i++]);
		free(strs);
		return (1);
	}
	return (0);
}

static char	save_words(char **strs, char const *str, char sep)
{
	int	length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		length = 0;
		while (str[i] == sep && str[i])
			i++;
		while (str[i] != sep && str[i])
		{
			length++;
			i++;
		}
		if (length)
		{
			if (safe_malloc(strs, j, length + 1))
				return (1);
			ft_strlcpy(strs[j++], &str[i - length], length + 1);
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (strs == NULL)
		return (NULL);
	strs[words] = NULL;
	if (save_words(strs, s, c))
		return (NULL);
	return (strs);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "tripouille";
	char	**strs = ft_split(str, ',');
	int	i;

	i = 0;
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}*/