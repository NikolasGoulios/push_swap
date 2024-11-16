/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:23:22 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/16 20:46:21 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_last_nodesize(t_node **a)
{
	t_node	*tmp;
	int		index;

	tmp = *a;
	index = 0;
	while (tmp)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}

t_node	*find_last(t_node *last_node)
{
	if (!last_node)
		return (NULL);
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

int	ft_stacksize(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_node	*find_max(t_node *a)
{
	t_node	*max;

	max = a;
	while (a)
	{
		if (a->nbr > max->nbr)
			max = a;
		a = a->next;
	}
	return (max);
}


