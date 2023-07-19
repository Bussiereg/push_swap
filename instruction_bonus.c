/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:32:35 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/28 13:35:06 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
