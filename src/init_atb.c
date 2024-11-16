/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:50:29 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/16 20:54:00 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_node *stack)
{
	int i;
	int median;

	i = 0;
	if (!stack)
		return;
	median = ft_stacksize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

