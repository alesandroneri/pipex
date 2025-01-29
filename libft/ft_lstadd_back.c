/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:34:14 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/04 12:06:07 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}

/*#include <stdio.h>
int	main(void)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	t_list	*node1 = (t_list *)malloc(sizeof(t_list));
	t_list	*node2 = (t_list *)malloc(sizeof(t_list));
	t_list	*node3 = (t_list *)malloc(sizeof(t_list));
	t_list	*node4 = (t_list *)malloc(sizeof(t_list));
	t_list	*node5 = (t_list *)malloc(sizeof(t_list));
	t_list	*node6 = (t_list *)malloc(sizeof(t_list));
	t_list	*current;
	t_list	*pos;
	t_list	*i;
	
	node->content = "teste";
	node1->content = "teste1";
	node2->content = "teste2";
	node3->content = "teste3";
	node4->content = "teste4";
	node5->content = "teste5";
	node6->content = "deu certo";
	
	node->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	printf("Linked list before: ");
	i = node;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next;
	}
	printf("NULL\n");
	ft_lstadd_back(&node, node6);
	printf("\n\n");
	printf("Linked list after adding one node in the back: ");
	i = node;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next;
	}
	printf("NULL\n");
	current = node;
	while (current != NULL)
	{
		pos = current->next;
		free(current);
		current = pos;
	}
	return (0);
}*/
