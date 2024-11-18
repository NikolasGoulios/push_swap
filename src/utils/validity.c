/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:23:29 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/18 04:09:57 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>
#define HASH_SIZE 1000

int is_stack_dublicate(t_node *a, long n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nbr == n)
        {
            printf("[DEBUG]: Duplicate value %ld found in stack\n", n);
            return (1);
        }
        a = a->next;
    }
    return (0);
}

int is_stack_ordered(t_node *a)
{
    t_node *current;

    current = a;
    if (!current)
        return (1);
    while (current->next)
    {
        if (current->nbr > current->next->nbr)
            return (0);
        current = current->next;
        if (current == a)
        	return (0);
    }
    return (1);
}

void	validate_stack(t_node *stack)
{
	t_node	*current;
	int		counter;

	current = stack;
	counter = 0;
	while (current)
	{
		current = current->next;
		counter++;
		if (counter > 100)
		{
			printf("[ERROR]: Circular reference detected in stack\n");
			return ;
		}
	}
	ft_printf("[PASSED]: Stack validation passed\n");
}