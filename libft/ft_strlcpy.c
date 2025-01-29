/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:43:43 by aneri-da          #+#    #+#             */
/*   Updated: 2024/09/27 11:43:57 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	i = 0;
	while ((i < size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}
/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	src[] = "teste";
	char	src2[] = "teste";
	char	dst[strlen(src)];
	char	dst2[strlen(src2)];

	printf("%zu\n", ft_strlcpy(dst, src, 6));
	printf("%s\n", dst);
	printf("%zu\n", strlcpy(dst2, src2, 6));
	printf("%s\n", dst2);
	return (0);
}*/
