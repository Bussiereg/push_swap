/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:21:32 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/28 13:30:19 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (*stack_b == NULL)
		return ;
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	push(t_node **head_src, t_node **head_dest)
{
	t_node	*temp1;
	t_node	*temp2;

	if (*head_src == NULL)
		return ;
	temp1 = (*head_src)->next;
	if (*head_dest == NULL)
	{
		(*head_dest) = (*head_src);
		(*head_dest)->next = NULL;
		(*head_src) = temp1;
		return ;
	}
	temp2 = (*head_dest);
	(*head_dest) = (*head_src);
	(*head_dest)->next = temp2;
	(*head_src) = temp1;
}
