/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/31 04:31:01 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**updated_args;

	a = NULL;
	b = NULL;
	updated_args = parsing_arguments(argc, argv);
	if (!updated_args)
		return (1);
	if (init_stack_a(&a, updated_args) == 1)
	{
		write (STDERR_FILENO, "Error\n", 6);
		cleanup(&a, &b, updated_args);
		return (1);
	}
	else
	{
		if (!is_stack_ordered(a))
			sort_fine_tuning(&a, &b);
	}
	cleanup(&a, &b, updated_args);
	return (0);
}
