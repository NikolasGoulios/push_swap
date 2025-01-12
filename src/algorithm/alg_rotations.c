/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 06:39:57 by ngoulios          #+#    #+#             */
/*   Updated: 2025/01/12 15:46:23 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_double_rotation(t_node **a, t_node **b, int direction);
static void	execute_single_rotation_b(t_node **b, int direction);
static void	execute_single_rotation_a(t_node **a, int direction);

void	execute_rotations(t_node **a, t_node **b, t_node *cheapest_node,
		int direction)
{
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	while (*b != cheapest_node->target_node || *a != cheapest_node)
	{
		if (*b != cheapest_node->target_node && *a != cheapest_node)
			execute_double_rotation(a, b, direction);
		else if (*b != cheapest_node->target_node)
			execute_single_rotation_b(b, direction);
		else
			execute_single_rotation_a(a, direction);
	}
}

static void	execute_double_rotation(t_node **a, t_node **b, int direction)
{
	if (direction == FORWARD)
		rr(a, b);
	else
		rrr(a, b);
}

static void	execute_single_rotation_b(t_node **b, int direction)
{
	if (direction == FORWARD)
		rb(b);
	else
		rrb(b);
}

static void	execute_single_rotation_a(t_node **a, int direction)
{
	if (direction == FORWARD)
		ra(a);
	else
		rra(a);
}
