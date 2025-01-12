/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:28:32 by ngoulios          #+#    #+#             */
/*   Updated: 2025/01/12 16:26:20 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stacks(t_node **a, t_node **b, t_node *cheapest_node, int i);
static void	move_a_to_b(t_node **a, t_node **b);
static void	move_b_to_a(t_node **a, t_node **b);

void	sort_turk(t_node **a, t_node **b, int size)
{
	if (!*a)
		return ;
	while (size-- > 3 && !is_stack_ordered(*a))
	{
		if (stack_size(*b) < 2)
			pb(b, a);
		else
		{
			init_nodes_a(*a, *b);
			move_a_to_b(a, b);
		}
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	if (!*b || !(*b)->target_node)
		return ;
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_stacks(a, b, cheapest_node, FORWARD);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rotate_stacks(a, b, cheapest_node, REVERSE);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	rotate_stacks(t_node **a, t_node **b, t_node *cheapest_node,
		int direction)
{
	if (!a || !b || !cheapest_node)
		return ;
	execute_rotations(a, b, cheapest_node, direction);
	current_index(*a);
	current_index(*b);
}
