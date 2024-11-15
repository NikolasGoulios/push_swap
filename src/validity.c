/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:23:29 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/15 22:59:31 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_dublicate(t_node *a)
{
	t_node	*current;
	t_node	*indexing;
	
	current = a;
	if(!current)
		return (0);
	while (current)
	{
		indexing = current->next;
		while (indexing)
		{
			if (current->nbr == indexing->nbr)
				return (1);
			indexing = indexing->next;
		}
	}
	return (0);
}

int is_stack_ordered(t_node *a)
{
    t_node *current;

    current = a;
    if (!current)
    {
        printf("[IS ORDERED]: Stack is empty, returning ordered\n");
        return (1);
    }

    printf("[IS ORDERED]: Starting stack traversal for is_stack_ordered\n");

    while (current->next)
    {
        printf("[IS ORDERED]: Current node: %d, Next node: %d\n", current->nbr, current->next->nbr);
        if (current->nbr > current->next->nbr)
        {
            printf("[IS ORDERED]: Stack is not ordered: %d > %d\n", current->nbr, current->next->nbr);
            return (0);
        }
        current = current->next;

        // Detect circular reference
        if (current == a)
        {
            printf("[IS ORDERED]: Error: Circular reference detected in stack\n");
            return (0);
        }
    }

    printf("[IS ORDERED]: Stack is ordered\n");
    return (1);
}


