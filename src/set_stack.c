/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:37:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 20:51:30 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_node **stack, long n);

void init_stack_a(t_node **a, char **arguments)
{
	// Initialize and store the arguments after that being checked and being parsed
	long	num;
	int 	i;

	i = 0;
	if(!arguments)
		return;
	while (arguments[i])
	{
		num = ft_atol(arguments[i]);
		if (num == -1 || num == 0)
		{
			error_indicator(a);
			return;
		}
		//dublication check 
		append_node(a, num);
		i++;
	}
	
}

static void	append_node(t_node **stack, long n)
{
	t_node	*node;
	t_node	*last_node;

	if(!stack)
		return;
	node = malloc(sizeof(t_node));
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
	return;
}
