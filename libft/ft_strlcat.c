/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:29:30 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/08 20:19:37 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	j;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size < dst_size)
		return (size + src_size);
	if (size == dst_size)
		return (src_size + dst_size);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while ((i + j) < (size - 1) && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (src_size + dst_size);
}
/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	dst[] = "teste";
	char	src[] = "cadete";
	char	dst2[] = "teste";
	char	src2[] = "cadete";

	printf("%zu\n", ft_strlcat(dst, src, -1));
	printf("%s\n", dst);
	printf("%zu\n", strlcat(dst2, src2, -1));
	printf("%s\n", dst2);
	return (0);
}*/