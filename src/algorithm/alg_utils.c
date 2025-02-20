/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:36:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/31 04:22:11 by ngoulios         ###   ########.fr       */
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

void	prep_push(t_node **stack, t_node *top_node, char stack_name)
{
	if (!stack || !*stack || !top_node || !node_exists_in_stack(*stack,
			top_node))
		return ;
	move_to_top(stack, top_node, stack_name);
}

void	move_to_top(t_node **stack, t_node *target_node, char stack_name)
{
	if (!stack || !*stack || !target_node)
		return ;
	while (*stack != target_node)
	{
		if (target_node->above_median)
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
		}
	}
}

void	min_on_top(t_node **a)
{
	t_node	*min_node;

	if (!a || !*a)
		return ;
	min_node = find_min(*a);
	move_to_top(a, min_node, 'a');
}
