/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:45:00 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/05 14:33:39 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*temp_src;
	unsigned char		*temp_dest;
	size_t				i;

	temp_dest = dest;
	temp_src = src;
	i = 0;
	if (temp_dest <= temp_src || temp_dest > (temp_src + n))
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
		dest = temp_dest;
		return (dest);
	}
	else
	{
		while (n--)
			temp_dest[n] = temp_src[n];
		dest = temp_dest;
		return (dest);
	}
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	//char	dest[] = "hello, world";
	//char	src[] = "hello, world";
	char	dest2[] = "hello, world";
	char	src2[] = "hello, world";

	//ft_memmove(dest + 7, src, 7);
	//printf("%s\n", dest);
	memmove(dest2 + 7, src2, 7);
	printf("%s\n", dest2);
	return (0);
}*/
