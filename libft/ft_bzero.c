/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:50:31 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/08 18:13:34 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "teste";
	char	str2[] = "teste";

	printf("Before: %s\n", str);
	ft_bzero(str, 5);
	printf("%s\n", str);
	printf("Before: %s\n", str2);
	bzero(str2, 5);
	printf("%s\n", str2);
	return (0);
}*/
