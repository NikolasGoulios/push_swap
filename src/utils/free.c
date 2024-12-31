/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:41:37 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/31 04:25:14 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_node **a, t_node **b, char **updated_args)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (updated_args)
		free_args(updated_args);
}

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

void	free_args(char **updated_args)
{
	int	i;

	i = 0;
	if (!updated_args)
		return ;
	while (updated_args[i])
	{
		if (updated_args[i])
		{
			free(updated_args[i]);
			updated_args[i] = NULL;
		}
		i++;
	}
	free(updated_args);
	updated_args = NULL;
}

void	free_av_arr(char **av_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (av_arr[i])
		{
			free(av_arr[i]);
			av_arr[i] = NULL;
		}
		i++;
	}
	free(av_arr);
}
