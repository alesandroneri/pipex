/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:02:31 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/16 15:41:18 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	check_base(char *numeric_base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (numeric_base[0] == '\0' || numeric_base[1] == '\0')
		return (0);
	while (numeric_base[i] != '\0')
	{
		if (numeric_base[i] == '-' || numeric_base[i] == '+')
			return (0);
		if (numeric_base[i] < 32 || numeric_base[i] > 126)
			return (0);
		j = i + 1;
		while (numeric_base[j] != '\0')
		{
			if (numeric_base[j] == numeric_base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base_count(unsigned int nbr, char *base)
{
	unsigned int	size_base;
	int				printf_len;

	printf_len = 0;
	size_base = ft_strlen(base);
	if (check_base(base))
	{
		if (nbr < size_base)
			printf_len += ft_putchar_count(base[nbr]);
		else
		{
			printf_len += ft_putnbr_base_count(nbr / size_base, base);
			printf_len += ft_putchar_count(base[nbr % size_base]);
		}
	}
	return (printf_len);
}
