/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:40:29 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/05 14:30:20 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*temp_src;
	unsigned char		*temp_dest;
	size_t				i;

	temp_dest = dest;
	temp_src = src;
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	dest = temp_dest;
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	dest[] = {"aabbcc"};
	char	dest2[] = {"aabbcc"};
	char	src[] = {"dddddd"};
	char	src2[] = {"dddddd"};

	printf("Minha: %s\n", (char *)memcpy(dest, src, 4));
	printf("Original: %s\n", (char *)memcpy(dest2, src2, 4));
	return (0);
}*/
