/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:37:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/13 22:40:35 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int init_stack_a(t_stack_node **a, char **arguments)
{
	// Initialize and store the arguments after that being checked and being parsed
	long	a;
	int 	i;

	i = 0;
	while (arguments[i])
	{
		a = (long)ft_atoi(arguments[i]); // Can I re-cast it into long from int ? Or rewrite the function by returnung long instead of ints ?
		if (a  > INT_MAX || a < INT_MIN)
			free(a);
		//dublication check 
		append_node(a, (int)a);
	}
	
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if(!stack)
		return;
	node = malloc(sizeof(t_stack_node));
	if(!node)
		return;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
