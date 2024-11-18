/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:41:37 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/18 20:02:43 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	error_indicator(t_node **a)
{
	fprintf(stderr, "Error\n");
	free_stack(a);
	exit(1);
}
void	free_args(char **updated_args)
{
	int i = 0;

	while (updated_args[i])
	{
		free(updated_args[i]);
		i++;
	}
	free(updated_args);
}