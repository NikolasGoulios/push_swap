/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:21:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 20:59:06 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A function to check the validity of the arguments 
char  **parsing_arguments(int argc, char **argv)
{
	char	**av_arr;
	int		i;
	
	i = 1;
	av_arr = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	else if (argc == 2)
	{
		av_arr = ft_split(argv[1], ' ');
		if (!av_arr)
			return (NULL);
	}
	else 
	{
		av_arr = malloc(sizeof(char *) * (argc));
		if (!av_arr)
			return (NULL);
		while (i < argc)
		{
			av_arr[i - 1] = ft_strdup(argv[i]);
			if (!av_arr[i - 1])
			{
				while (--i >= 1)
					free(av_arr[i - 1]);
				free(av_arr);
				return (NULL); //Allocation from strdup add a printf to inform the cindition of the allocation
			}
			i++;
		}
		av_arr[i] = NULL;
	}
	return (av_arr);
}
