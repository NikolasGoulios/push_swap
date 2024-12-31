/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:21:57 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/31 03:12:13 by ngoulios         ###   ########.fr       */
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
	if (!av_arr || !is_valid_integer(*av_arr))
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_args(av_arr);
		return (NULL);
	}
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
			free_av_arr(av_arr, i - 1);
			return (NULL);
		}
		i++;
	}
	return (av_arr);
}
