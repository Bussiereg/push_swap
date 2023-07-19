/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:58:16 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 15:58:54 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*temp1;
	t_node	*save;
	t_node	*curr;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	curr = *head;
	temp1 = *head;
	while (curr->next->next != NULL)
		curr = curr->next;
	save = curr->next;
	curr->next = NULL;
	save->next = temp1;
	*head = save;
}

void	rra(t_node	**stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node	**stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node	**stack_a, t_node	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
