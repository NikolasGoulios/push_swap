/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:23:22 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/15 19:27:51 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_last_nodesize(t_node **a)
{
	t_node	*tmp;
	int				index;

	tmp = *a;
	index = 0;
	while (tmp)
	{
		tmp = tmp ->next;
		index++;
	}
	return (index);
}

long	ft_atol(const char *str)
{
	// Add it to Libft baby, its a nice function
	long	results;
	long	sign;
	int		i;

	results = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		results = results * 10 + (str[i] - '0');
		if (results * sign > LONG_MAX)
			return (-1);
		if (results * sign < LONG_MIN)
			return (0);
		i++;
	}
	return (results * sign);
}

t_node *find_last(t_node *last_node)
{
	if (!last_node){
		printf("Error: Stack is empty in find_last\n");
		return (NULL);
	}
	while (last_node->next){
		printf("Traversing node: %d\n", last_node->nbr);
		last_node = last_node->next;
	}
	printf("Last node found: %d\n", last_node->nbr);
	return (last_node);
}

int ft_stacksize(t_node *stack)
{
    int size = 0;

    while (stack)
    {
        size++;
        printf("Counting node: %d\n", stack->nbr); // Debug print
        stack = stack->next;
    }
    printf("Total stack size: %d\n", size);
    return size;
}


void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("Node debug from print_stack function: %d\n", stack->nbr);
        stack = stack->next;
    }
}

t_node	*find_max(t_node *a)
{
	t_node *max;

	max = a;
	while (a)
	{
		if (a->nbr > max->nbr)
			max = a;
		a = a->next;
	}
	return (max);
}

void validate_stack(t_node *stack)
{
    t_node *current = stack;
    int counter = 0;

    printf("Validating stack...\n");
    while (current)
    {
        printf("Node: %d\n", current->nbr);
        current = current->next;

        counter++;
        if (counter > 100) // Arbitrary limit to detect infinite loops
        {
            printf("Error: Circular reference detected in stack\n");
            return;
        }
    }
    printf("Stack validation passed\n");
}
