/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:23:29 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/13 23:31:48 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_dublicate(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*indexing;
	
	current = a;
	if(!current)
		return (0);
	while (current)
	{
		indexing = current->next;
		while (indexing)
		{
			if (current->nbr == indexing->nbr)
				return (1);
			indexing = indexing->next;
		}
	}
	return (0);
}

int stack_shorted(t_stack_node *a)
{
	t_stack_node	*current;

	current = a;
	if(!current)
		return (1);
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

