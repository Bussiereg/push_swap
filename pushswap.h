/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:40:19 by gbussier          #+#    #+#             */
/*   Updated: 2023/03/27 15:35:26 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"
# include <stdlib.h>

typedef struct snode
{
	int				x;
	int				index;
	struct snode	*next;
}					t_node;

/*swap functions*/
void		swap(t_node **head);
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);

/*push functions*/
void		push(t_node **head_src, t_node **head_dest);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);

/*rotate functions*/
void		rotate(t_node **head);
void		ra(t_node	**stack_a);
void		rb(t_node	**stack_b);
void		rr(t_node	**stack_a, t_node	**stack_b);

/*reverse rotate functions*/
void		reverse_rotate(t_node **head);
void		rra(t_node	**stack_a);
void		rrb(t_node	**stack_b);
void		rrr(t_node	**stack_a, t_node	**stack_b);

/*cost of move functions*/
int			nb_reverse_rotate(t_node **stack, int ref);
int			nb_rotate(t_node **stack, int ref);
int			nb_reverse_rotate_max(t_node **stack, int max);
int			nb_rotate_max(t_node **stack, int max);

/*list utilities*/
t_node		*ps_lstnew(int value);
void		ps_lstadd_back(t_node **lst, t_node *new);
t_node		*ps_lstlast(t_node *lst);
void		print_list(t_node *lst);
int			lst_max(t_node **stack_a);
int			lst_min(t_node **stack_a);
int			ps_lstsize(t_node *lst);
int			ps_lstlast_index(t_node **lst);

/*Check functions*/
int			check_order(t_node **stack);
int			check_sort(t_node **stack_a, t_node **stack_b);
int			check_input(char *input);
int			check_double(t_node **stack);
long long	ps_atoi(const char *str);

/*Sorting Algorithm*/
void		complex_algo(t_node **stack_a, t_node **stack_b);

#endif
