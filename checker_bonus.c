/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:15:47 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/28 13:18:27 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	deallocate(t_node **root)
{
	t_node	*aux;
	t_node	*curr;

	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free (aux);
	}
	*root = NULL;
	return (0);
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	if (check_sort(stack_a, stack_b) == 1)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
	}
	deallocate(stack_a);
	deallocate(stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		tmp = ps_lstnew(ft_atoi(argv[i]));
		ps_lstadd_back(&stack_a, tmp);
		if (check_input(argv[i++]) == -1 || check_double(&stack_a) == -1)
		{
			deallocate(&stack_a);
			return (ft_printf("Error\n"));
		}
	}
	if (execute_instruction(&stack_a, &stack_b) == 0)
		return (deallocate(&stack_a));
	checker(&stack_a, &stack_b);
	return (0);
}
