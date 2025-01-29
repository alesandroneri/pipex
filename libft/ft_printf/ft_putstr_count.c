/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:53:40 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/15 15:41:42 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr_count(char *str)
{
	int	i;

	if (str == NULL)
		return (ft_putstr_count("(null)"));
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return (i);
}
