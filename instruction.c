#include "pushswap.h"

void	sa(node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}


void	sb(node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(node **stack_a, node **stack_b)
{
	swap(stack_a);
	swap(stack_b);	
	ft_printf("ss\n");
}

void	pa(node **stack_a, node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");	
}

void	pb(node **stack_a, node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");	
}

void	ra(node	**stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(node	**stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(node	**stack_a, node	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rra(node	**stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(node	**stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(node	**stack_a, node	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

void	swap(node **head)
{
	node *temp1;

	if (*head == NULL || (*head)->next == NULL)
		return;
	temp1 = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp1->next = *head;
	*head = temp1;
}

void	push(node **head_src, node **head_dest)
{
 	node *temp1;
 	node *temp2;

	if (*head_src == NULL)
		return;
	temp1 = (*head_src)->next;
	if (*head_dest == NULL)
	{
		(*head_dest) = (*head_src);
		(*head_dest)->next = NULL;
		(*head_src) = temp1;
		return;		
	}
	temp2 = (*head_dest);
	(*head_dest) = (*head_src);
	(*head_dest)->next = temp2;
	(*head_src) = temp1;
}
 
void	rotate(node **head)
{
	node *temp1;
	node *curr;
	
	if (*head == NULL || (*head)->next == NULL)
		return;
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

void	reverse_rotate(node **head)
{
	node *temp1;
	node *save;
	node *curr;
	
	if (*head == NULL || (*head)->next == NULL)
		return;
	curr = *head;
	temp1 = *head;
	while (curr->next->next != NULL)
		curr = curr->next;
	save = curr->next;
	curr->next = NULL;
	save->next = temp1;
	*head = save;
}