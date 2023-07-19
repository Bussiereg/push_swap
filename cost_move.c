/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:43:44 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 13:45:27 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	nb_rotate(t_node **stack, int ref)
{
	int		result;
	t_node	*curr;

	curr = *stack;
	result = 0;
	while (curr->next != NULL)
	{
		if (curr->index <= ref)
			return (result);
		result++;
		curr = curr->next;
	}
	return (result);
}

int	nb_reverse_rotate(t_node **stack, int ref)
{
	int		size;
	int		i;
	int		result;
	t_node	*curr;

	result = 1;
	i = 0;
	size = ps_lstsize(*stack);
	while (size--)
	{
		curr = *stack;
		i = size;
		while (i--)
		{
			curr = curr->next;
		}
		if (curr->index <= ref)
			return (result);
		result++;
	}
	return (result);
}

int	nb_rotate_max(t_node **stack, int max)
{
	int		result;
	t_node	*curr;

	curr = *stack;
	result = 0;
	while (curr->next != NULL)
	{
		if (curr->index == max)
			return (result);
		result++;
		curr = curr->next;
	}
	return (result);
}

int	nb_reverse_rotate_max(t_node **stack, int max)
{
	int		size;
	int		i;
	int		result;
	t_node	*curr;

	result = 1;
	i = 0;
	size = ps_lstsize(*stack);
	while (size--)
	{
		curr = *stack;
		i = size;
		while (i--)
		{
			curr = curr->next;
		}
		if (curr->index == max)
			return (result);
		result++;
	}
	return (result);
}
