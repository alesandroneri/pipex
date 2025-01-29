/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:51:27 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 14:08:56 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int	ft_put_ptr(void *ptr);
int	ft_putchar_count(char c);
int	ft_putstr_count(char *str);
int	ft_putnbr_count(int nb);
int	ft_putnbr_base_count(unsigned int nbr, char *base);
int	ft_printf(const char *format, ...);

#endif
