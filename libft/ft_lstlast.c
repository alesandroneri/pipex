/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:31:17 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/04 16:54:50 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*i;

	i = lst;
	if (i == NULL)
		return (NULL);
	while (i->next != NULL)
		i = i->next;
	return (i);
}

/*#include <stdio.h>
int	main(void)
{
	t_list	*node =	(t_list *)malloc(sizeof(t_list));
	t_list	*node1 = (t_list *)malloc(sizeof(t_list));
	t_list	*node2 = (t_list *)malloc(sizeof(t_list));
	t_list	*node3 = (t_list *)malloc(sizeof(t_list));
	t_list	*node4 = (t_list *)malloc(sizeof(t_list));
	t_list	*node5 = (t_list *)malloc(sizeof(t_list));
	t_list	*node6 = (t_list *)malloc(sizeof(t_list));
	t_list	*node7 = (t_list *)malloc(sizeof(t_list));
	t_list	*node8 = (t_list *)malloc(sizeof(t_list));
	t_list	*node9 = (t_list *)malloc(sizeof(t_list));
	t_list	*last;
	t_list	*i;

	node->content = "testando";
	node1->content = "se";
	node2->content = "eu";
	node3->content = "consigo";
	node4->content = "exibir";
	node5->content = "o";
	node6->content = "ultimo";
	node7->content = "elemento";
	node8->content = "da";
	node9->content = "lista";

	node->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = NULL;

	printf("Linked list: ");
	i = node;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next;	
	}
	printf("NULL\n");
	printf("\n\n");
	printf("The last node of the linked list: ");
	last = ft_lstlast(node);
	if (last != NULL)
		printf("%s -> ", (char *)last->content);
	printf("NULL\n");
		
	free(node);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);
	free(node7);
	free(node8);
	free(node9);
	return (0);
}*/
