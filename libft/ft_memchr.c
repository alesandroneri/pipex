/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:37:17 by aneri-da          #+#    #+#             */
/*   Updated: 2024/12/28 14:54:03 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int     main(void)
{
    char    str[] = {0, 1, 2, 3, 4, 5};
    int		c = 2;
    char    *result;
    //char    *result2;

    result = (char *)ft_memchr(str, c, 3);
    ft_memchr(str, c, 3);
    printf("%d %s\n", c, result);
    //result2 = (char *)memchr(str, c, 3);
    //memchr(str, c, 3);
    //printf("%d %s", c, result2);
    return(0);
}*/
