/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:28:55 by aneri-da          #+#    #+#             */
/*   Updated: 2024/10/09 14:21:23 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
void	*ft_putstrupper(void *str)
{
	char	*new_str;
	int		i;

	new_str = ft_strdup((char *)str);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (new_str[i] != '\0')
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
		i++;
	}
	return (new_str);
}

void	delete(void *content)
{
	free(content);
}

#include <stdio.h>
int	main(void)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	t_list	*node1 = (t_list *)malloc(sizeof(t_list));
	t_list	*node2 = (t_list *)malloc(sizeof(t_list));
	t_list	*node3 = (t_list *)malloc(sizeof(t_list));
	t_list	*node4 = (t_list *)malloc(sizeof(t_list));
	t_list	*node5 = (t_list *)malloc(sizeof(t_list));
	t_list	*node6 = (t_list *)malloc(sizeof(t_list));
	t_list	*new_list;
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

	printf("Linked list: ");
	i = node;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next;
	}
	printf("NULL\n");
	
	new_list = ft_lstmap(node, ft_putstrupper, delete);
	printf("\n\n");
	printf("New linked list after applying the function in each node: ");
	i = new_list;
	while (i != NULL)
	{
		printf("%s -> ", (char *)i->content);
		i = i->next;
	}
	printf("NULL\n");
	
	clear_lst(node, delete);
	clear_lst(new_list, delete); 
	return (0);
}*/
