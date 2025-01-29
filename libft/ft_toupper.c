/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:34 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/04 16:06:48 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_toupper('a'));
	printf("%d\n", toupper('a'));
	return (0);
}*/