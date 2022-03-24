/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:17:17 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/24 13:43:24 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// Swaps first two elements of a stack | sa and sb

int	swap(t_list **stack)
{
	t_list	*node;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	node = *stack;
	next = node->next;
	if (!node && !next)
		ft_print("Error occured while swapping!");
	tmp_val = node->value;
	tmp_index = node->index;
	node->value = next->value;
	node->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{	
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

// pa and pb

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*node_to;
	t_list	*node_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	node_to = *stack_to;
	node_from = *stack_from;
	tmp = node_from;
	node_from = node_from->next;
	*stack_from = node_from;
	if (!node_to)
	{
		node_to = tmp;
		node_to->next = NULL;
		*stack_to = node_to;
	}
	else
	{
		tmp->next = node_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

// Shift up all elements of a stack by 1. The first element becomes the last one | ra and rb

int	rotate(t_list **stack)
{
	t_list	*node;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	node = *stack;
	tail = ft_lstlast(node);
	*stack = node->next;
	node->next = NULL;
	tail->next = node;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}


// Shifts down all elements of a stack by 1. The last element becomes the first one | rra and rrb

int	reverseRotate(t_list **stack)
{
	t_list	*node;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	node = *stack;
	tail = ft_lstlast(node);
	while (node)
	{
		if (node->next->next == NULL)
		{
			 node->next = NULL;
			 break ;
		}
		node = node->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
