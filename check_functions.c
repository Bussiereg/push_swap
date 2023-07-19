/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:47:31 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 15:54:54 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long long	ps_atoi(const char *str)
{
	int			i;
	int			signe;
	long long	result;

	signe = 1;
	result = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * signe);
}

int	check_order(t_node **stack)
{
	t_node	*curr;

	curr = *stack;
	while (curr->next != NULL)
	{
		if (curr->x > curr->next->x)
			return (-1);
		curr = curr->next;
	}
	return (1);
}

int	check_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*curr;

	curr = *stack_a;
	if (*stack_b != NULL)
		return (-1);
	while (curr->next != NULL)
	{
		if (curr->x > curr->next->x)
			return (-1);
		curr = curr->next;
	}
	return (1);
}

int	check_input(char *input)
{
	size_t	i;

	i = 0;
	if (ps_atoi(input) > 2147483647 || ps_atoi(input) < -2147483648)
		return (-1);
	if (ft_strlen(input) == 1 && (input[0] == '-' || input[0] == '+'))
		return (-1);
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (i < ft_strlen(input))
	{
		if (input[i] < '0' || input[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	check_double(t_node **stack)
{
	t_node	*curr;
	t_node	*comp;

	curr = *stack;
	comp = ps_lstlast(*stack);
	while (curr->next != NULL)
	{
		if (comp->x == curr->x)
			return (-1);
		curr = curr->next;
	}
	return (1);
}
