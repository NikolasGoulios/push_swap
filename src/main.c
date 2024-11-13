/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/13 16:47:11 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Declare pointers to two data structures/linked lists, one for stack `a` and another for `b`
	//Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks
int main (int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL; //Set them to Null to avoid undifined behaviour
	b = NULL;
	parsing_arguments(argc, argv);
	init_stack_a(&a, argv + 1);
	if (is_dublicate(a))
		return (NULL);
	if(!stack_shorted(a))
	{
		// Short jusrt swap them 2 
		// Short 3 inside stack 
		// Short the rest using both stack 
	}
	//Freeeeeee
	free_stack(&a);
	return (0);
}

char  **parsing_arguments(int argc, char **argv)
{
	char	**av_arr;
	int		i;
	
	i = 1;
	// How to parse the arguments? 
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (ft_printf("Memory allocation Failed , Split"));
	}
	else 
	{
		av_arr = malloc(sizeof(char *) * argc);
		if (!av_arr)
			return (NULL);
		while (i < argc - 1)
		{
			av_arr[i] = ft_strdup(argv[i]); //strdup will handle the NULL cases and the allocation fails
			if (!av_arr[i])
				return (NULL); //Allocation from strdup add a printf to inform the cindition of the allocation
			i++;
		}
		av_arr[i] = NULL;
	}
		return (av_arr);
}

int init_stack_a(t_stack_node *a, char **argv)
{
	// Initialize and store the arguments after that being checked and being parsed
	
}

int stack_shorted(t_stack_node *a)
{
	// Check if the stack is already shorted
}

void free_stack(t_stack_node *a)
{
	// Free the shit out of the memory babyyy. Dont forget that
	// you have this function and double free anything AGAIN 
	// cause valgrind will find it and you will not be able to locate it 
	// AGAIN
}
//Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
	//If input errors, return error

//Handle both cases of input, whether a variable number of command line arguments, or as a string
	//If the input of numbers is as a string, call split() to split the substrings

//Initialize stack `a` by appending each input number as a node to stack `a`
	//Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or `-` `+` signs
		//If errors found, free stack `a` and return error
	//Check for each input, if it is a long integer
		//If the input is a string, convert it to a long integer 
	//Append the nodes to stack `a`

//Check if stack `a` is sorted
	//If not sorted, implement our sorting algorithm 
		//Check for 2 numbers
			//If so, simply swap the numbers
		//Check for 3 numbers
			//If so, implement our simple `sort three` algorithim
		//Check if the stack has more than 3 numbers
			//If so, implent our Turk Algorithm

//Clean up the stack