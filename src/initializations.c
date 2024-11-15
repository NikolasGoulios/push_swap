/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:28:45 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/15 19:04:20 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	short_initialize(t_node **a, t_node *b)
{
	int	n;
	
	(void)b;
	n = ft_stacksize(*a);
	if (n == 1)
		return ;
	else if (n == 2)
		sa(a);
	}
}*/


void	short_initialize(t_node **a, t_node *b) //debug from chatgtp cause I am bugging my brain
{
	printf("Entering short_initialize\n");
    int n;

    (void)b; // b is unused here
    n = ft_stacksize(*a);
    printf("Stack size in short_initialize: %d\n", n);

    if (n == 2)
    {
        printf("Node 1: %d, Node 2: %d\n", (*a)->nbr, (*a)->next->nbr);
        if (!is_stack_ordered(*a))
        {
            printf("Condition met for sa: %d > %d\n", (*a)->nbr, (*a)->next->nbr);
            sa(a);
        }
        else
        {
            printf("Condition not met: %d <= %d\n", (*a)->nbr, (*a)->next->nbr);
        }
    }
    else if (n == 3)
   {
        printf("Stack has 3 nodes. Performing sort_three...\n");

        if (!is_stack_ordered(*a))
        {
            sort_three(a); // Call a function to handle sorting for 3 nodes
            printf("sort_three executed\n");
        }
        else
        {
            printf("Stack is already ordered\n");
        }
    }
    else
    {
        printf("Unexpected stack size in short_initialize: %d\n", n);
    }
}



