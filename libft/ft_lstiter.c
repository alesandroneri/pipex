/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:20:51 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/09 14:32:14 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*#include <stdio.h>

void	ft_putstr(void *str)
{
	int	i;

	i = 0;
	while (((char *)str)[i] != '\0')
	{
		if (((char *)str)[i] >= 'a' && ((char *)str)[i] <= 'z')
			((char *)str)[i] -= 32;
		i++;
	}
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
	t_list	*current;
	t_list	*pos;
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
	ft_lstiter(node, ft_putstr);
	printf("Linked list after applying the function in each node: ");
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
