/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:23:29 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 22:17:44 by ngoulios         ###   ########.fr       */
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

/*int is_stack_ordered(t_node *a)
{
	t_node	*current;

	current = a;
	if(!current)
		return (1);
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}*/

int is_stack_ordered(t_node *a)
{
    t_node *current;

    current = a;
    if (!current)
    {
        printf("Stack is empty, returning ordered\n");
        return (1);
    }

    printf("Starting stack traversal for is_stack_ordered\n");

    while (current->next)
    {
        printf("Current node: %d, Next node: %d\n", current->nbr, current->next->nbr);
        if (current->nbr > current->next->nbr)
        {
            printf("Stack is not ordered: %d > %d\n", current->nbr, current->next->nbr);
            return (0);
        }
        current = current->next;

        // Detect circular reference
        if (current == a)
        {
            printf("Error: Circular reference detected in stack\n");
            return (0);
        }
    }

    printf("Stack is ordered\n");
    return (1);
}


