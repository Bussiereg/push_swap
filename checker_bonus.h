/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:32:00 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/28 13:32:12 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "libft/libft.h"
# include <stdlib.h>

typedef struct snode
{
	int				x;
	int				index;
	struct snode	*next;
}					t_node;

/*basic list manipulation commands*/
void		swap(t_node **head);
void		push(t_node **head_src, t_node **head_dest);
void		rotate(t_node **head);
void		reverse_rotate(t_node **head);

/*executive instructions*/
int			execute_swap(t_node **stack_a, t_node **stack_b, char *cmd);
int			execute_rotate(t_node **stack_a, t_node **stack_b, char *cmd);
int			execute_rev_rotate(t_node **stack_a, t_node **stack_b, char *cmd);
int			execute_push(t_node **stack_a, t_node **stack_b, char *cmd);
int			execute_instruction(t_node **stack_a, t_node **stack_b);

/*list utilities*/
t_node		*ps_lstnew(int value);
void		ps_lstadd_back(t_node **lst, t_node *new);
t_node		*ps_lstlast(t_node *lst);
void		print_list(t_node *lst);

/*Check functions*/
int			check_order(t_node **stack);
int			check_sort(t_node **stack_a, t_node **stack_b);
int			check_input(char *input);
int			check_double(t_node **stack);
long long	ps_atoi(const char *str);

#endif
