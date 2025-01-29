/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:33:50 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/05 14:09:35 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*#include <stdio.h>
#include <string.h>
int	main (void)
{
	char	str[] = "dddd";
	char	mem[]= "dddd"; 
	ft_memset(str, 'a', 2);
	printf("%s\n", str);
	memset(mem, 'a', 2);
	printf("%s\n", mem);
	return (0);
}*/
