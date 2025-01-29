/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:06:11 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/07 18:15:40 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_ocurrence;
	int			i;

	last_ocurrence = NULL;
	i = 0;
	while (((char *)s)[i] != '\0')
	{
		if (((char *)s)[i] == (char)c)
			last_ocurrence = &s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return ((char *)last_ocurrence);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[] = "alessandro";
	char	c = 'z';
	char	s2[] = "alessandro";
	char	a = 'z';
	char	*result;
	char	*result2;

	result = ft_strrchr(s, c);
	result2 = strrchr(s2, a);

	printf("%c %s\n", c, result);
	printf("%c %s\n", a, result2);
	return (0);
}*/