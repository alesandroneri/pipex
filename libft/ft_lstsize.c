/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:19:54 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/04 16:53:54 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*i;

	i = lst;
	if (i == NULL)
		return (0);
	count = 0;
	while (i != NULL)
	{
		count++;
		i = i->next;
	}
	return (count);
}
/*#include <stdio.h>
int	main(void)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	t_list *node3 = (t_list *)malloc(sizeof(t_list));
	t_list *node4 = (t_list *)malloc(sizeof(t_list));
	t_list *node5 = (t_list *)malloc(sizeof(t_list));
	t_list *i;

	node->content = "teste";
	node1->content = "teste1";
	node2->content = "teste2";
	node3->content = "teste3";
	node4->content = "teste4";
	node5->content = "teste5";

	node->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	printf("Linked list: ");
	i = node;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next;
	}
	printf("NULL\n");
	printf("\n\n");
	printf("Size of the linked list: %d\n", ft_lstsize(node));
	free(node);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return (0);
}*/
