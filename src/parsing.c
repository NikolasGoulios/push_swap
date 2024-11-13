/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:21:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/13 22:38:58 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// A function to check the validity of the arguments 
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