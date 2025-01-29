/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:29:32 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/07 16:28:36 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (((char *)s)[i] != '\0')
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
#include "libft.h"
int	main(void)
{
	char	s[] = "encontre a letra m nessa string";
	char	c = 'm';
	char	*result;
	char	s2[] = "encontre a letra m nessa string";
	char	a = 'm';
	char	*result2;
	result = ft_strchr(s, c);
	result2 = strchr(s2, a);
	if (result != NULL && result2 != NULL)
	{
		printf("A letra %c, %s\n", c, result);
		printf("A letra %c, %s\n", a, result2);
	}
	return (0);
}*/
