/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:36:46 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/08 19:07:00 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	end;

	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	i = 0;
	while (is_set(s1[i], set))
		i++;
	while (is_set(s1[end], set))
		end--;
	return (ft_substr(s1, i, end -(i - 1)));
}
/*#include <stdio.h>
int     main(void)
{
    char    str[] = "abb testando se vai da certo abb";
    char    set[] = "abb";
	char 	*strtrim;

	strtrim = ft_strtrim(str, set);
	if (strtrim != NULL)
	{
    	printf("%s\n", strtrim);
    	free(strtrim);
	}
    return (0);

}*/