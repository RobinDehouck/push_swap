/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:17:40 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/23 14:23:43 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// here, our stack is already indexed in asorting order. This function will calculate the nb of bits max (of the maxindex, not the maxvalue)
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

// Radix Sort : Sorting with the radix method is simple : you will sort index by index.
// for example : 21 10 11
// first, at indexmax with have : 1 0 1
// we sort this, it gives us 0 1 1, which is 10 21 11
// let's now sort at indexmax - 1 : 1 2 1
// we sort this, it gives us 1 1 2, which is 10 11 21. The radix sort is finished and the list have been sorted.

// Radix Sort with Binaries : Since we only have 2 stacks, we will need to sort using binaries. 
// 0 = 0 // 1 = 1 // 2 = 10 // 3 = 11 // 4 = 100 // 5 = 101 // 6 = 110 
// By looking as these numbers, you can understand how the radix sort will be applied. At a given index, we will separate the 0s from the 1s.

// if the element's binary value at a selected index == 1, then push this element
// at the end of stack_a. If it's a 0, push it to b. When all element have been treated, push everything back to a, and start again.
// proceed until we iterated max_bits times.

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}