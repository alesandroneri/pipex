/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:06:21 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 14:04:34 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] <= 32)
		if (nptr[i] == '\e' || nptr[i++] == '\0')
			return (0);
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("-10"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("-+100"));
	printf("%d\n", ft_atoi("+10"));
	printf("%d\n", ft_atoi("\n20"));
	printf("%d\n", ft_atoi(" 30"));
	printf("%d\n", ft_atoi("100"));
	return (0);
}*/