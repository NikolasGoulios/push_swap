/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:28:32 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/16 18:56:13 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
static void	move_a_to_b(t_node **a, t_node **b);
static void	move_b_to_a(t_node **a, t_node **b);

void	sort_turk(t_node **a, t_node **b, int size)
{
	printf("[TURK]: Turk Logic initialized");
	if (size-- > 3 && !is_stack_ordered(*a))
		pb(b, a);
	if (size-- > 3 && !is_stack_ordered(*a))
		pb(b, a);
	while (size-- > 3 && !is_stack_ordered(*a))
	{
		init_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}