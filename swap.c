/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:46:24 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 15:47:02 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_node **head)
{
	t_node	*temp1;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp1 = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp1->next = *head;
	*head = temp1;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	sa(t_node **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}
