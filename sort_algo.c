/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:59:20 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/28 15:06:50 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_in_gap(int max, t_node **stack)
{
	t_node	*curr;

	curr = *stack;
	while (curr != NULL)
	{
		if (curr->index <= max)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	very_small_list(t_node **stack_a)
{
	while (check_order(stack_a) != 1)
	{
		if ((*stack_a)->x > (*stack_a)->next->x)
			sa(stack_a);
		else
			rra(stack_a);
	}
}

int	calculate_key(t_node **stack)
{
	int	length;

	length = ps_lstsize(*stack);
	if (length <= 10)
		return (2);
	else if (length <= 100)
		return ((length - 10) * 0.023 + 2);
	else if (length <= 500)
		return ((length - 100) * 0.015 + 4);
	else
		return ((length - 500) * 0.015 + 10);
}

void	push_with_gap(t_node **stack_a, t_node **stack_b, int gap)
{
	int	pos_max;
	int	max_index;

	max_index = lst_max(stack_a);
	pos_max = gap;
	while (ps_lstsize(*stack_a) > 3)
	{
		while (check_in_gap(pos_max, stack_a) == 1)
		{
			if ((*stack_a)->index <= pos_max)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->index < pos_max - (gap / 2))
					rb(stack_b);
			}
			else if (nb_reverse_rotate(stack_a, pos_max)
				> nb_rotate(stack_a, pos_max))
				ra(stack_a);
			else
				rra(stack_a);
		}
		pos_max = pos_max + gap;
		if (pos_max >= max_index)
			pos_max = max_index - 3;
	}
}

void	complex_algo(t_node **stack_a, t_node **stack_b)
{
	int	gap;

	gap = ps_lstsize(*stack_a) / calculate_key(stack_a);
	if (check_sort(stack_a, stack_b) == -1)
		push_with_gap(stack_a, stack_b, gap);
	very_small_list(stack_a);
	while (check_sort(stack_a, stack_b) == -1)
	{
		if ((*stack_b)->index == lst_max(stack_b))
			pa(stack_a, stack_b);
		else if (nb_reverse_rotate_max(stack_b, lst_max(stack_b))
			> nb_rotate_max(stack_b, lst_max(stack_b)))
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
