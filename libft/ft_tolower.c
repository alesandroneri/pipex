/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:36:54 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/04 16:07:04 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_tolower('B'));
	printf("%d\n", tolower('B'));
	return (0);
}*/
