/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:28:45 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/15 22:52:47 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_initialize(t_node **a, t_node *b)
{
	printf("Entering short_initialize\n");
    int n;

    (void)b; // b is unused here
    n = ft_stacksize(*a);
    printf("[INITIALAZATION]:Stack size in short_initialize: %d\n", n);

    if (n == 2)
    {
        printf("[INITIALAZATION]:Node 1: %d, Node 2: %d\n", (*a)->nbr, (*a)->next->nbr);
        if (!is_stack_ordered(*a))
        {
            printf("[INITIALAZATION]:Condition met for sa: %d > %d\n", (*a)->nbr, (*a)->next->nbr);
            sa(a);
        }
        else
        {
            printf("[INITIALAZATION]:Condition not met: %d <= %d\n", (*a)->nbr, (*a)->next->nbr);
        }
    }
    else if (n == 3)
   {
        printf("[INITIALAZATION]:Stack has 3 nodes. Performing sort_three...\n");

        if (!is_stack_ordered(*a))
        {
            sort_three(a); // Call a function to handle sorting for 3 nodes
            printf("[INITIALAZATION]:sort_three executed\n");
        }
        else
        {
            printf("[INITIALAZATION]:Stack is already ordered\n");
        }
    }
    else
    {
        printf("[INITIALAZATION]:Unexpected stack size in short_initialize: %d\n", n);
    }
}



