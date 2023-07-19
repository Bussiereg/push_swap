/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:14:56 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 13:58:07 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"	

void	ps_index(t_node **stack)
{
	t_node	*curr1;
	t_node	*curr2;
	int		pos;

	curr1 = *stack;
	while (curr1 != NULL)
	{
		curr2 = *stack;
		pos = 0;
		while (curr2 != NULL)
		{
			if (curr2->x <= curr1->x)
				pos++;
			curr2 = curr2->next;
		}
		curr1->index = pos;
		curr1 = curr1->next;
	}
}

void	deallocate(t_node **root)
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
		if (check_input(argv[i]) == -1 || check_double(&stack_a) == -1)
		{
			deallocate(&stack_a);
			return (ft_printf("Error\n"));
		}
		i++;
	}
	ps_index(&stack_a);
	complex_algo(&stack_a, &stack_b);
	deallocate(&stack_a);
	return (0);
}
