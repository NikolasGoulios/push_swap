/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:36:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/28 20:56:27 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	node_exists_in_stack(t_node *stack, t_node *target_node)
{
	while (stack)
	{
		if (stack == target_node)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	rotate_to_top(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	prep_push(t_node **stack, t_node *top_node, char stack_name)
{
	if (!stack || !*stack || !top_node)
		return ;
	if (!node_exists_in_stack(*stack, top_node))
		return ;
	rotate_to_top(stack, top_node, stack_name);
}

void	min_on_top(t_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
