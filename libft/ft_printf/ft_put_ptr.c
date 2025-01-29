/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:58:45 by aneri-da          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:43 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_hexabase(unsigned long nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_hexabase(nb / 16);
	count += ft_putchar_count(base[nb % 16]);
	return (count);
}

int	ft_put_ptr(void	*ptr)
{
	int				printf_len;
	unsigned long	adress;

	adress = (unsigned long)ptr;
	printf_len = 0;
	if (ptr == NULL)
		printf_len += ft_putstr_count("(nil)");
	else
	{
		printf_len = ft_putstr_count("0x");
		printf_len += ft_hexabase(adress);
	}
	return (printf_len);
}
