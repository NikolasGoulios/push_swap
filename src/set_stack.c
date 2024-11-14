/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:37:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 21:57:06 by ngoulios         ###   ########.fr       */
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
	if(!a)
		return;
	printf("Initializing stack...\n");
	while (arguments && arguments[i])
	{
		printf("Parsing argument: %s\n", arguments[i]);
		num = ft_atol(arguments[i]);
		if (num == -1 || num == 0)
		{
			printf("Error: Invalid number %ld\n", num);
			error_indicator(a);
			return;
		}
		//dublication check 
		append_node(a, num);
		printf("Added %ld to the stack\n", num);
		i++;
	}
	
}

static void	append_node(t_node **stack, long n)
{
	t_node	*node;
	t_node	*last_node;

	if(!stack){
		printf("Error: Stack pointer is NULL\n");
		return;
	}
	node = malloc(sizeof(t_node));
	if(!node){
		printf("Error: malloc failed for new node\n");
		return;
	}
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if(!(*stack))
	{
		printf("Appending as the first node\n");
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		if (!last_node)
		{
			printf("Error: find_last returned NULL\n");
			free(node);
			return;
		}
		printf("Appending %ld after %d\n", n, last_node->nbr);
		last_node->next = node;
		node->prev = last_node;
	}
	return;
}
