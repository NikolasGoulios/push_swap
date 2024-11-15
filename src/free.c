/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:41:37 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/15 22:56:06 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_node **stack)
{
    t_node *tmp;
    t_node *current;

    if (!stack || !(*stack)) // Check both stack pointer and head
        return;

    current = *stack;
    while (current)
    {
        tmp = current->next;
        printf("[FREE]: Freeing node: %d\n", current->nbr); // Debug print
        free(current);
        current = tmp;
    }
    *stack = NULL;
    printf("[FREE]:Stack successfully freed\n");
}


void	error_indicator(t_node **a)
{
	free_stack(a);
	ft_printf("[ERROR]: Define Nice errors in Header");
	exit(1);
	// or free and exit inside the free_stack function
}
