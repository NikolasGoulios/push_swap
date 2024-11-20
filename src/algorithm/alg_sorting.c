/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:28:32 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/20 18:40:04 by ngoulios         ###   ########.fr       */
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
	if (size-- > 3 && !is_stack_ordered(*a))
		pb(b, a);
	if (size-- > 3 && !is_stack_ordered(*a))
		pb(b, a);
	while (size-- > 3 && !is_stack_ordered(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
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

/*static void	move_b_to_a(t_node **a, t_node **b)
{
	int count = 0;

	if (!b || !*b) // Ensure Stack B is not NULL or empty
		return;

	while (*b) // Loop until Stack B is empty
	{
		if ((*b)->target_node)
			prep_for_push(a, (*b)->target_node, 'a'); // Prepare for push

		// Directly implement the logic of pa
		t_node *temp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		temp->next = *a;
		if (*a)
			(*a)->prev = temp;
		*a = temp;

		count++;
	}

	// Output the optimized single command
	printf("pa %d\n", count);
}*/

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

/*
#include <stdio.h> // For debug printing

static void	rotate_stacks(t_node **a, t_node **b, t_node *cheapest_node, int i);
static void	move_a_to_b(t_node **a, t_node **b);
static void	move_b_to_a(t_node **a, t_node **b);

void	sort_turk(t_node **a, t_node **b, int size)
{
	printf("Starting sort_turk with size = %d\n", size);
	if (!*a)
	{
		printf("Error: Stack A or B is NULL.\n");
		return ;
	}

	// Push elements from A to B if size > 3 and A is unordered
	if (size-- > 3 && !is_stack_ordered(*a))
	{
		printf("Pushing top of Stack A to Stack B.\n");
		pb(b, a);
	}
	if (size-- > 3 && !is_stack_ordered(*a))
	{
		printf("Pushing top of Stack A to Stack B again.\n");
		pb(b, a);
	}

	// Main sorting loop for Stack A
	while (size-- > 3 && !is_stack_ordered(*a))
	{
		printf("Initializing nodes for Stack A and B.\n");
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}

	// Sort the remaining three elements in Stack A
	printf("Sorting the top 3 elements in Stack A.\n");
	sort_three(a);

	// Move all elements from Stack B back to Stack A
	while (*b)
	{
		printf("Initializing nodes for Stack B.\n");
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}

	// Finalize the order in Stack A
	printf("Updating indices and moving the minimum to the top in Stack A.\n");
	current_index(*a);
	min_on_top(a);
	printf("sort_turk completed successfully.\n");
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	if (!*b || !(*b)->target_node)
	{
		printf("Error: Stack B is empty or target node is NULL.\n");
		return ;
	}

	printf("Preparing to push target node %d from Stack B to Stack A.\n", (*b)->target_node->nbr);
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
	printf("Node pushed successfully from Stack B to Stack A.\n");
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node)
	{
		printf("Error: No cheapest node found in Stack A.\n");
		return ;
	}

	printf("Cheapest node found in Stack A: %d\n", cheapest_node->nbr);
	if (!cheapest_node->target_node)
	{
		printf("Error: Cheapest node does not have a target node.\n");
		return ;
	}

	printf("Target node for cheapest node: %d\n", cheapest_node->target_node->nbr);

	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		printf("Both nodes are above median. Rotating stacks forward.\n");
		rotate_stacks(a, b, cheapest_node, FORWARD);
	}
	else if (!cheapest_node->above_median && !cheapest_node->target_node->above_median)
	{
		printf("Both nodes are below median. Rotating stacks in reverse.\n");
		rotate_stacks(a, b, cheapest_node, REVERSE);
	}

	printf("Preparing for push from Stack A to B.\n");
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
	printf("Node pushed successfully from Stack A to Stack B.\n");
}

static void	rotate_stacks(t_node **a, t_node **b, t_node *cheapest_node, int direction)
{
	if (!a || !b || !cheapest_node)
	{
		printf("Error: Invalid parameters for rotate_stacks.\n");
		return ;
	}

	printf("Executing rotations for cheapest node %d in direction: %s\n",
		   cheapest_node->nbr, direction == FORWARD ? "FORWARD" : "REVERSE");

	execute_rotations(a, b, cheapest_node, direction);

	printf("Updating indices for Stack A and Stack B after rotations.\n");
	current_index(*a);
	current_index(*b);
	printf("Rotations completed successfully.\n");
}

*/