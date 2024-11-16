/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/16 17:31:23 by ngoulios         ###   ########.fr       */
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
	{
		printf("[MAIN / Error]: Invalid input\n");
		return (1);
	}
	printf("[MAIN]:Arguments parsed successfully\n");
	init_stack_a(&a, updated_args);
	printf("[MAIN]:Stack initialized, calling is_stack_ordered...\n");
	if (!is_stack_ordered(a))
	{
		printf("[MAIN]:Stack is not ordered, calling short_initialize...\n");
		short_initialize(&a, &b);
	}
	else
		printf("[MAIN]: Stack is already ordered\n");
	free_stack(&a);
	free_stack(&b);
	// Free memory allocated in parsing_arguments
	for (int i = 0; updated_args[i]; i++)
		free(updated_args[i]);
	free(updated_args);
	return (0);
}
