/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/18 06:29:57 by ngoulios         ###   ########.fr       */
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
	init_stack_a(&a, updated_args);
	if (!is_stack_ordered(a))
		sort_fine_tuning(&a, &b);
	if (a)
		free_stack(&a);
	if (b)
		free_stack(&b);
	free_args(updated_args);
	return (0);
}
