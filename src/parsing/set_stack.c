/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:37:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/20 18:31:54 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		append_node(t_node **stack, long n);
static t_node	*create_node(long n);

void	init_stack_a(t_node **a, char **arguments)
{
	long	num;
	int		i;

	i = 0;
	if (!a)
		return ;
	while (arguments && arguments[i])
	{
		num = ft_atol(arguments[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			error_indicator(a);
			return ;
		}
		if (is_stack_dublicate(*a, num))
			return ;
		append_node(a, num);
		i++;
	}
}

static void	append_node(t_node **stack, long n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = create_node(n);
	if (!node)
		return ;
	if (!(*stack))
	{
		*stack = node;
	}
	else
	{
		last_node = find_last(*stack);
		if (!last_node)
		{
			free(node);
			return ;
		}
		last_node->next = node;
		node->prev = last_node;
	}
}

static t_node	*create_node(long n)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	node->prev = NULL;
	return (node);
}

/*#include <stdio.h> // For debug printing
#include <limits.h> // For INT_MAX and INT_MIN
#include <stdlib.h> // For malloc, free

static void		append_node(t_node **stack, long n);
static t_node	*create_node(long n);


void	init_stack_a(t_node **a, char **arguments)
{
	long	num;
	int		i;

	printf("Initializing stack A...\n");
	i = 0;
	if (!a)
	{
		printf("Error: Stack A is NULL.\n");
		return ;
	}
	while (arguments && arguments[i])
	{
		printf("Processing argument[%d]: '%s'\n", i, arguments[i]);
		num = ft_atol(arguments[i]);
		printf("Converted to number: %ld\n", num);

		if (num > INT_MAX || num < INT_MIN)
		{
			printf("Error: Number out of range [%d, %d]: %ld\n", INT_MIN, INT_MAX, num);
			error_indicator(a);
			return ;
		}

		if (is_stack_dublicate(*a, num))
		{
			printf("Error: Duplicate detected for number: %ld\n", num);
			error_indicator(a);
			return ;
		}

		printf("Appending number to stack: %ld\n", num);
		append_node(a, num);
		i++;
	}
	printf("Stack A initialized successfully.\n");
}

static void	append_node(t_node **stack, long n)
{
	t_node	*node;
	t_node	*last_node;

	printf("Appending node with number: %ld\n", n);
	if (!stack)
	{
		printf("Error: Stack is NULL.\n");
		return ;
	}
	node = create_node(n);
	if (!node)
	{
		printf("Error: Failed to create node for number: %ld\n", n);
		return ;
	}

	if (!(*stack))
	{
		printf("Stack is empty. Setting first node.\n");
		*stack = node;
	}
	else
	{
		printf("Finding last node in stack...\n");
		last_node = find_last(*stack);
		if (!last_node)
		{
			printf("Error: Failed to find last node in stack.\n");
			free(node);
			return ;
		}
		printf("Last node found. Adding node to the end.\n");
		last_node->next = node;
		node->prev = last_node;
	}
	printf("Node appended successfully: %ld\n", n);
}

static t_node	*create_node(long n)
{
	t_node	*node;

	printf("Creating node for number: %ld\n", n);
	node = malloc(sizeof(t_node));
	if (!node)
	{
		printf("Error: Memory allocation failed for node.\n");
		return (NULL);
	}
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	node->prev = NULL;
	printf("Node created successfully: %ld\n", n);
	return (node);
}*/
