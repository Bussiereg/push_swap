/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:49:24 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 13:49:39 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*ps_lstnew(int value)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(*head));
	if (!head)
		return (NULL);
	head->x = value;
	head->next = NULL;
	return (head);
}

void	print_list(t_node *lst)
{
	while (lst)
	{
		ft_printf("valeur est :%d    index est: %d\n", lst->x, lst->index);
		lst = lst->next;
	}
}

void	ps_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ps_lstlast(*lst);
			tmp->next = new;
		}
	}
}

t_node	*ps_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
