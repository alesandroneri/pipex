/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:45:42 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/16 15:38:19 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	number_len(int n)
{
	int			len;
	long int	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_count(int nb)
{
	int		c;

	c = 0;
	if (nb == -2147483648)
	{
		ft_putchar_count('-');
		ft_putchar_count('2');
		c += 1 + ft_putnbr_count(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar_count('-');
		ft_putnbr_count(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr_count(nb / 10);
		ft_putnbr_count(nb % 10);
	}
	else
		ft_putchar_count(nb + 48);
	return (number_len(nb));
}
