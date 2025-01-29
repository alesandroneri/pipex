/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:48:47 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/16 15:50:57 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_choosing_format(const char format, va_list args)
{
	int	printf_len;

	printf_len = 0;
	if (format == 'c')
		printf_len += ft_putchar_count((char)va_arg(args, int));
	else if (format == 'd' || format == 'i')
		printf_len += ft_putnbr_count((int)va_arg(args, int));
	else if (format == 's')
		printf_len += ft_putstr_count(va_arg(args, char *));
	else if (format == 'u')
		printf_len += ft_putnbr_base_count
			((int)va_arg(args, int), "0123456789");
	else if (format == 'x')
		printf_len += ft_putnbr_base_count
			((int)va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		printf_len += ft_putnbr_base_count
			((int)va_arg(args, int), "0123456789ABCDEF");
	else if (format == 'p')
		printf_len += ft_put_ptr(va_arg(args, void *));
	else if (format == '%')
		printf_len += ft_putchar_count('%');
	return (printf_len);
}

int	ft_printf(const char *format, ...)
{
	va_list				args;
	int					printf_len;
	int					i;

	va_start(args, format);
	i = 0;
	printf_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			printf_len += ft_choosing_format(format[i + 1], args);
			i++;
		}
		else
			printf_len += ft_putchar_count(format[i]);
		i++;
	}
	va_end(args);
	return (printf_len);
}
