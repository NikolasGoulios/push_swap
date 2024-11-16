/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:23:22 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/15 23:03:21 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_last_nodesize(t_node **a)
{
	t_node	*tmp;
	int		index;

	tmp = *a;
	index = 0;
	while (tmp)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}

t_node	*find_last(t_node *last_node)
{
	if (!last_node)
	{
		printf("Error: Stack is empty in find_last\n");
		return (NULL);
	}
	while (last_node->next)
	{
		printf("Traversing node: %d\n", last_node->nbr);
		last_node = last_node->next;
	}
	printf("Last node found: %d\n", last_node->nbr);
	return (last_node);
}

int	ft_stacksize(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		printf("Counting node: %d\n", stack->nbr); // Debug print
		stack = stack->next;
	}
	printf("Total stack size: %d\n", size);
	return (size);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("Node debug from print_stack function: %d\n", stack->nbr);
		stack = stack->next;
	}
}

t_node	*find_max(t_node *a)
{
	t_node	*max;

	max = a;
	while (a)
	{
		if (a->nbr > max->nbr)
			max = a;
		a = a->next;
	}
	return (max);
}

void	validate_stack(t_node *stack)
{
	t_node	*current;
	int		counter;

	current = stack;
	counter = 0;
	printf("Validating stack...\n");
	while (current)
	{
		printf("Node: %d\n", current->nbr);
		current = current->next;
		counter++;
		if (counter > 100) // Arbitrary limit to detect infinite loops
		{
			printf("Error: Circular reference detected in stack\n");
			return ;
		}
	}
	printf("Stack validation passed\n");
}
