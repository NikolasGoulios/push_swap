/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:31:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/16 18:31:43 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dst)
{
	t_node	*pushed_node;
	
	pushed_node = NULL;
	if (!*src)
		return;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (!*dst)
	{
		*dst = pushed_node;
		pushed_node->next = NULL;
	}
	else 
	{
		pushed_node->next = *dst;
		pushed_node->next->prev = pushed_node;
		*dst = pushed_node;
	}	
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
