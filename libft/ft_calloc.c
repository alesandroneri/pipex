/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:08:56 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/08 19:29:53 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*vector_calloc;

	if (size != 0)
		if (((nmemb * size) / size) != nmemb)
			return (NULL);
	vector_calloc = (void *)malloc(size * nmemb);
	if (vector_calloc == NULL)
		return (NULL);
	ft_bzero(vector_calloc, nmemb * size);
	return (vector_calloc);
}

/*int	main(void)
{
	int		*my_calloc;
	size_t	i;

	my_calloc = (int *)ft_calloc(10, sizeof(int));
	i = 0;
	while (i < 10)
	{
		printf("%d", my_calloc[i]);
		i++;
	}
	return (0);
}*/
