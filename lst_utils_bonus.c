/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:28:56 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/28 13:29:14 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	print_list(t_node *lst)
{
	while (lst)
	{
		ft_printf("valeur est :%d\n", lst->x);
		lst = lst->next;
	}
}
