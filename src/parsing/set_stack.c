/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:37:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/18 06:35:52 by ngoulios         ###   ########.fr       */
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
		{
			error_indicator(a);
			return ;
		}
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
