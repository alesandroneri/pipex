/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:46 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/08 15:58:00 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			i;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && temp_s1[i] == temp_s2[i])
		i++;
	return (temp_s1[i] - temp_s2[i]);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
	int    str[] = {10, 10, 10, 40};
	int    str2[] = {10, 10, 10, 10};
	int	i;
	int	j;

	i = 0;
	printf("%d\n", ft_memcmp(str, str2, sizeof(int)*4));
	printf("%d\n", memcmp(str, str2, sizeof(int)*4));
	while (i < 4)
	{
		printf("%d ", str[i]);
		i++;
	}
	printf("\n\n");
	j = 0;
	while (j < 4)
	{
		printf("%d ", str2[j]);
		j++;
	}
	return (0);
}*/
