/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:20:12 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/24 13:43:24 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// This function will return the node with the minimal value with isn't indexed already in our stack ( == index == -1)
static t_list	*return_min(t_list **stack)
{
	t_list	*node;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	node = *stack;
	if (node)
	{
		while (node)
		{
			if ((node->index == -1) && (!has_min || node->value < min->value))
			{
				min = node;
				has_min = 1;
			}
			node = node->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*node;
	int		index;

	index = 0;
	node = return_min(stack);
	while (node)
	{
		node->index = index++;
		node = return_min(stack);
	}
}