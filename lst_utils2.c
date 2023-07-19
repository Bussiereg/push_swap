/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:47:50 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 13:48:38 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	lst_max(t_node **stack_a)
{
	t_node	*curr;
	int		max;

	curr = *stack_a;
	max = curr->index;
	while (curr->next != NULL)
	{
		if (curr->next->index > max)
			max = curr->next->index;
		curr = curr->next;
	}
	return (max);
}

int	lst_min(t_node **stack_a)
{
	t_node	*curr;
	int		min;

	curr = *stack_a;
	min = curr->index;
	while (curr->next != NULL)
	{
		if (curr->next->index < min)
			min = curr->next->index;
		curr = curr->next;
	}
	return (min);
}

int	ps_lstsize(t_node *lst)
{
	int	size;

	size = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int	ps_lstlast_index(t_node **lst)
{
	if (*lst == NULL)
		return (0);
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
	}
	return ((*lst)->index);
}
