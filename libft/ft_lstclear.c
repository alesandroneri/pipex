/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:24:11 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/04 15:04:25 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		temp2 = temp->next;
		del(temp->content);
		free(temp);
		temp = temp2;
	}
	*lst = NULL;
}
/*#include <stdio.h>

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	t_list	*node1 = (t_list *)malloc(sizeof(t_list));
	t_list	*node2 = (t_list *)malloc(sizeof(t_list));
	t_list	*node3 = (t_list *)malloc(sizeof(t_list));
	t_list	*node4 = (t_list *)malloc(sizeof(t_list));
	t_list	*node5 = (t_list *)malloc(sizeof(t_list));
	t_list	*node6 = (t_list *)malloc(sizeof(t_list));
	t_list	*i;

	node->content = ft_strdup("teste");
	node1->content = ft_strdup("teste1");
	node2->content = ft_strdup("teste2");
	node3->content = ft_strdup("teste3");
	node4->content = ft_strdup("teste4");
	node5->content = ft_strdup("teste5");
	node6->content = ft_strdup("teste6");

	node->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = NULL;

	printf("Linked list before: ");
	i = node;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next;
	}
	printf("NULL\n");
	printf("\n\n");
	ft_lstclear(&node, del);
	
	if (node == NULL)
		printf("Linked list has been succesfuly removed.\n");
	else
		printf("Linked list still exists.\n");
	return (0);
}*/
