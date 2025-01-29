/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:48:42 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/04 14:06:09 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
/*#include <stdio.h>
int	main(void)
{
	char	str[] = "teste";
	t_list	*head_node;
	
	head_node = ft_lstnew(str);
	printf("New linked list: ");
	printf("%s -> ", (char *)head_node->content);
	printf("NULL\n");
	return (0);
}*/
