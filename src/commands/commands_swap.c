/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:05:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 22:10:10 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;
	
	if (!head || !(*head) || !(*head)->next)
		return;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_node **a)
{
	printf("Calling sa function\n");

	swap(a);
	ft_printf("sa\n");
}

// next swaping commands for 2 and three and then the turk algorithm