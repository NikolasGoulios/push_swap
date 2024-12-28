/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_targetA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:50:00 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/28 20:57:11 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost_analysis_a(t_node *a, t_node *b);
static void	set_target_a(t_node *a, t_node *b);

void	init_nodes_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

/*static void	cost_analysis_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost += len_a - (a->target_node->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}*/

static void cost_analysis_a(t_node *a, t_node *b)
{
    int len_a = stack_size(a);
    int len_b = stack_size(b);

    while (a)
    {
        int forward_cost_a = a->index;
        int reverse_cost_a = len_a - a->index;

        // Calculate the cost of moving `a` to the top
        a->push_cost = (forward_cost_a < reverse_cost_a) ? forward_cost_a : reverse_cost_a;

        // Add the cost of moving `a`'s target to the top of `b`
        if (a->target_node)
        {
            int forward_cost_b = a->target_node->index;
            int reverse_cost_b = len_b - a->target_node->index;
            a->push_cost += (forward_cost_b < reverse_cost_b) ? forward_cost_b : reverse_cost_b;
        }

        a = a->next;
    }
}


/*static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}*/

static void set_target_a(t_node *a, t_node *b)
{
    while (a)
    {
        t_node *current_b = b;
        long best_match_index = LONG_MIN;
        t_node *best_target = NULL;

        while (current_b)
        {
            if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
            {
                best_match_index = current_b->nbr;
                best_target = current_b;
            }
            current_b = current_b->next;
        }

        if (!best_target) // If no valid target, set to max
            a->target_node = find_max(b);
        else
            a->target_node = best_target;

        a = a->next;
    }
}

