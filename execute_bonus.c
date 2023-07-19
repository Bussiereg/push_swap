/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gbussier <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/28 13:21:02 by gbussier		  #+#	#+#			 */
/*   Updated: 2023/03/28 13:28:35 by gbussier         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "checker_bonus.h"

int	execute_swap(t_node **stack_a, t_node **stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
	{
		swap(stack_a);
		return (1);
	}
	if (ft_strncmp(cmd, "sb\n", 3) == 0)
	{
		swap(stack_b);
		return (1);
	}
	if (ft_strncmp(cmd, "ss\n", 3) == 0)
	{
		swap(stack_a);
		swap(stack_b);
		return (1);
	}
	return (0);
}

int	execute_rotate(t_node **stack_a, t_node **stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
	{
		rotate(stack_a);
		return (1);
	}
	if (ft_strncmp(cmd, "rb\n", 3) == 0)
	{
		rotate(stack_b);
		return (1);
	}
	if (ft_strncmp(cmd, "rr\n", 3) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		return (1);
	}
	return (0);
}

int	execute_rev_rotate(t_node **stack_a, t_node **stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "rra\n", 4) == 0)
	{
		reverse_rotate(stack_a);
		return (1);
	}
	if (ft_strncmp(cmd, "rrb\n", 4) == 0)
	{
		reverse_rotate(stack_b);
		return (1);
	}
	if (ft_strncmp(cmd, "rrr\n", 4) == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		return (1);
	}
	return (0);
}

int	execute_push(t_node **stack_a, t_node **stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
	{
		push(stack_b, stack_a);
		return (1);
	}
	if (ft_strncmp(cmd, "pb\n", 3) == 0)
	{
		push(stack_a, stack_b);
		return (1);
	}
	return (0);
}

int	execute_instruction(t_node **stack_a, t_node **stack_b)
{
	char	*instruction;
	int		ind;

	instruction = get_next_line(0);
	if (instruction == NULL)
		return (1);
	while (instruction != NULL)
	{
		ind = 0;
		ind = ind + execute_swap(stack_a, stack_b, instruction);
		ind = ind + execute_rotate(stack_a, stack_b, instruction);
		ind = ind + execute_rev_rotate(stack_a, stack_b, instruction);
		ind = ind + execute_push(stack_a, stack_b, instruction);
		if (ind == 0)
		{
			ft_printf("Error\n");
			free (instruction);
			return (0);
		}
		free (instruction);
		instruction = get_next_line(0);
	}
	free (instruction);
	return (1);
}
