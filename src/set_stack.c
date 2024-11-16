/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:37:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/16 17:26:02 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_node **stack, long n);

void init_stack_a(t_node **a, char **arguments)
{
	// Initialize and store the arguments after that being checked and being parsed
	long	num;
	int 	i;
	int 	flag;
	
	i = 0;
	flag = 0;
	if(!a)
		return;
	printf("[SET STACK]: Initializing stack...\n");
	while (arguments && arguments[i])
	{
		printf("[SET STACK]: Parsing argument: %s\n", arguments[i]);
		num = ft_atol(arguments[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			printf("[SET STACK / Error]: Invalid number %ld\n", num);
			error_indicator(a);
			return;
		}
		//dublication check 
		append_node(a, num);
		printf("[SET STACK]: Added %ld to the stack\n", num);
		i++;
	}
	
}

static void	append_node(t_node **stack, long n)
{
	t_node	*node;
	t_node	*last_node;

	if(!stack){
		printf("[SET STACK / Error]: Stack pointer is NULL\n");
		return;
	}
	node = malloc(sizeof(t_node));
	if(!node){
		printf("[SET STACK / Error]: malloc failed for new node\n");
		return;
	}
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if(!(*stack))
	{
		printf("[SET STACK]: Appending as the first node\n");
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		if (!last_node)
		{
			printf("[SET STACK / Error]: find_last returned NULL\n");
			free(node);
			return;
		}
		printf("[SET STACK]: Appending %ld after %d\n", n, last_node->nbr);
		last_node->next = node;
		node->prev = last_node;
	}
	return;
}
