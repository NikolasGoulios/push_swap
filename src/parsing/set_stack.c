/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:37:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/31 02:21:06 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		append_node(t_node **stack, long n);
static t_node	*create_node(long n);

int	init_stack_a(t_node **a, char **arguments)
{
	long	num;
	int		i;

	i = 0;
	if (!a)
		return (1);
	while (arguments && arguments[i])
	{
		if (is_valid_integer(arguments[i]))
			num = ft_atol(arguments[i]);
		else
			return (1);
		if (num > INT_MAX || num < INT_MIN || is_stack_duplicate(*a, num))
			return (1);
		append_node(a, num);
		i++;
	}
	return (0);
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
