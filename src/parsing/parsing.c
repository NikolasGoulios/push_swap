/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:21:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/20 19:09:01 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_single_argument(char *arg);
static char	**split_multiple_arguments(int argc, char **argv);

char	**parsing_arguments(int argc, char **argv)
{
	char	**av_arr;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	else if (argc == 2)
		av_arr = split_single_argument(argv[1]);
	else
		av_arr = split_multiple_arguments(argc, argv);
	return (av_arr);
}

static char	**split_single_argument(char *arg)
{
	char	**av_arr;

	av_arr = ft_split(arg, ' ');
	if (!av_arr)
		return (NULL);
	return (av_arr);
}

static char	**split_multiple_arguments(int argc, char **argv)
{
	char	**av_arr;
	int		i;

	av_arr = ft_calloc(argc, sizeof(char *));
	if (!av_arr)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		av_arr[i - 1] = ft_strdup(argv[i]);
		if (!av_arr[i - 1])
		{
			while (--i >= 1)
				free(av_arr[i - 1]);
			free(av_arr);
			return (NULL);
		}
		i++;
	}
	return (av_arr);
}

/*#include <stdio.h> // Include for debugging purposes
#include "push_swap.h"

static char	**split_single_argument(char *arg);
static char	**split_multiple_arguments(int argc, char **argv);

char	**parsing_arguments(int argc, char **argv)
{
	char	**av_arr;

	// Debugging input arguments
	printf("parsing_arguments called with argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
		printf("argv[%d] = '%s'\n", i, argv[i]);

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		printf("Returning NULL: no valid arguments provided.\n");
		return (NULL);
	}
	else if (argc == 2)
	{
		printf("Splitting single argument: '%s'\n", argv[1]);
		av_arr = split_single_argument(argv[1]);
	}
	else
	{
		printf("Splitting multiple arguments.\n");
		av_arr = split_multiple_arguments(argc, argv);
	}

	// Debugging result
	if (av_arr)
	{
		printf("Parsed arguments:\n");
		for (int i = 0; av_arr[i]; i++)
			printf("av_arr[%d] = '%s'\n", i, av_arr[i]);
	}
	else
	{
		printf("Parsed arguments: NULL\n");
	}
	return (av_arr);
}

static char	**split_single_argument(char *arg)
{
	char	**av_arr;

	printf("split_single_argument called with arg = '%s'\n", arg);
	av_arr = ft_split(arg, ' ');
	if (!av_arr)
	{
		printf("ft_split failed: returning NULL\n");
		return (NULL);
	}

	// Debugging split results
	printf("Result from ft_split:\n");
	for (int i = 0; av_arr[i]; i++)
		printf("av_arr[%d] = '%s'\n", i, av_arr[i]);

	return (av_arr);
}

static char	**split_multiple_arguments(int argc, char **argv)
{
	char	**av_arr;
	int		i;

	printf("split_multiple_arguments called with argc = %d\n", argc);
	av_arr = ft_calloc(argc, sizeof(char *));
	if (!av_arr)
	{
		printf("Memory allocation failed: returning NULL\n");
		return (NULL);
	}

	i = 1;
	while (i < argc)
	{
		printf("Copying argv[%d] = '%s' to av_arr[%d]\n", i, argv[i], i - 1);
		av_arr[i - 1] = ft_strdup(argv[i]);
		if (!av_arr[i - 1])
		{
			printf("Memory allocation failed for av_arr[%d]\n", i - 1);
			while (--i >= 1)
			{
				printf("Freeing av_arr[%d] = '%s'\n", i - 1, av_arr[i - 1]);
				free(av_arr[i - 1]);
			}
			free(av_arr);
			return (NULL);
		}
		i++;
	}
	printf("Successfully split multiple arguments.\n");

	// Debugging final result
	printf("Resulting array:\n");
	for (int j = 0; av_arr[j]; j++)
		printf("av_arr[%d] = '%s'\n", j, av_arr[j]);

	return (av_arr);
}*/

