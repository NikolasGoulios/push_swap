/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:23:29 by ngoulios          #+#    #+#             */
/*   Updated: 2025/01/12 11:26:01 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_duplicate(t_node *a, long n)
{
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_stack_ordered(t_node *a)
{
	t_node	*current;

	current = a;
	if (!current)
		return (1);
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
		if (current == a)
			return (0);
	}
	return (1);
}

// void	validate_stack(t_node *stack)
// {
// 	t_node *current;
// 	int counter;

// 	current = stack;
// 	counter = 0;
// 	while (current)
// 	{
// 		current = current->next;
// 		counter++;
// 		if (counter > 100)
// 			return ;
// 	}
// }

int	is_valid_integer(char *arg)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	if (*arg == '\0')
		return (0);
	while (*arg)
	{
		if (*arg == '-' || *arg == '+')
			return 0;
		if (!ft_isdigit((unsigned char)*arg))
			return (0);
		arg++;
	}
	return (1);
}
