/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_targetA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:50:00 by ngoulios          #+#    #+#             */
/*   Updated: 2025/01/13 14:49:22 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	evaluate_push_costs_a(t_node *a, t_node *b);
static void	set_target_a(t_node *a, t_node *b);
static int	calculate_cost(int index, int length);

void	calculate_metadata_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	evaluate_push_costs_a(a, b);
	set_cheapest(a);
}

static int	calculate_cost(int index, int length)
{
	int	forward_cost;
	int	reverse_cost;

	forward_cost = index;
	reverse_cost = length - index;
	if (forward_cost < reverse_cost)
		return (forward_cost);
	else
		return (reverse_cost);
}

static void	evaluate_push_costs_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(a);
	len_b = get_stack_size(b);
	while (a)
	{
		a->push_cost = calculate_cost(a->index, len_a);
		if (a->target_node)
		{
			a->push_cost += calculate_cost(a->target_node->index, len_b);
		}
		a = a->next;
	}
}

static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	long	best_match_index;
	t_node	*best_target;

	while (a)
	{
		current_b = b;
		best_match_index = LONG_MIN;
		best_target = NULL;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				best_target = current_b;
			}
			current_b = current_b->next;
		}
		if (!best_target)
			a->target_node = find_max(b);
		else
			a->target_node = best_target;
		a = a->next;
	}
}
