/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:42:54 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 15:43:51 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_node **head)
{
	t_node	*temp1;
	t_node	*curr;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	curr = *head;
	temp1 = (*head)->next;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = *head;
	curr->next->next = NULL;
	*head = temp1;
}

void	ra(t_node	**stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node	**stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_node	**stack_a, t_node	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
