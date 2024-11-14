/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:28:45 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 22:21:15 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	short_initialize(t_node **a, t_node *b)
{
	int	n;
	
	(void)b;
	n = ft_stacksize(*a);
	printf("Stack size: %d\n", n);
	if (n == 1)
		return ;
	else if (n == 2){
		printf("Swapping nodes %d and %d\n", (*a)->nbr, (*a)->next->nbr);
		sa(a);
	}
}*/
void short_initialize(t_node **a, t_node *b) //debug from chatgtp cause I am bugging my brain
{
	printf("Entering short_initialize\n");
    int n;

    (void)b; // b is unused here
    n = ft_stacksize(*a);
    printf("Stack size in short_initialize: %d\n", n);

    if (n == 2)
    {
        printf("Node 1: %d, Node 2: %d\n", (*a)->nbr, (*a)->next->nbr);
        if ((*a)->nbr > (*a)->next->nbr)
        {
            printf("Condition met for sa: %d > %d\n", (*a)->nbr, (*a)->next->nbr);
            sa(a);
        }
        else
        {
            printf("Condition not met: %d <= %d\n", (*a)->nbr, (*a)->next->nbr);
        }
    }
    else
    {
        printf("Stack size is not 2, skipping sa\n");
    }
}


