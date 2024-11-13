/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 00:11:30 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Declare pointers to two data structures/linked lists, one for stack `a` and another for `b`
//Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks
int main (int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**updated_args;

	a = NULL;
	b = NULL;
	updated_args = NULL;
	updated_args = parsing_arguments(argc, argv);
	init_stack_a(&a, updated_args);
	if (stack_dublicate(a))
		return (NULL);
	if(!stack_shorted(a))
		short_initialize(a, b);
	free_stack(&a);
	return (0);
}

void	short_initialize(t_stack_node **a, t_stack_node *b)
{
	int	n;
	
	n = ft_stacksize(*a);
	if (n == 1)
		return (1);
	else if (n == 2)
		short_two(a);
}