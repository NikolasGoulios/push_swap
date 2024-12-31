/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:31:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/31 04:31:24 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dst)
{
	t_node	*pushed_node;

	if (!src || !(*src))
		return ;
	pushed_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->next = NULL;
	pushed_node->prev = NULL;
	if (!*dst)
		*dst = pushed_node;
	else
	{
		pushed_node->next = *dst;
		(*dst)->prev = pushed_node;
		*dst = pushed_node;
	}
}

void	pb(t_node **b, t_node **a)
{
	push(a, b);
	ft_printf("pb\n");
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}
