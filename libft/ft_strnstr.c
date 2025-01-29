/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:42:40 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/07 18:49:32 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	i = 0;
	while ((i < len) && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	big[] = "aaab";
	char	little[] = "ms";
	char	big2[] = "aaab";
	char	little2[] = "ms";

	printf("%s\n", ft_strnstr(big, little, 30));
	printf("%s\n", strnstr(big2, little2, 30));
	return (0);
}*/