/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:46:59 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/07 14:45:48 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
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
	t_list	*i;

	node->content = ft_strdup("teste");
	node1->content = ft_strdup("teste1");
	node2->content = ft_strdup("teste2");
	node3->content = ft_strdup("teste3");
	node4->content = ft_strdup("teste4");
	node5->content = ft_strdup("teste5");

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
	ft_lstdelone(node3, del);
	printf("\n\n");
	printf("Linked list after removing one node: ");	
	node2->next = node4;
	i = node;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next; 
	}
	printf("NULL\n");
	return (0);
}*/
