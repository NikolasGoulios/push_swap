/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:28:45 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/16 20:40:02 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_fine_tuning(t_node **a, t_node **b)
{
	int	n;

	n = ft_stacksize(*a);
	if (n == 2 && !is_stack_ordered(*a))
			sa(a);
	else if (n == 3 && !is_stack_ordered(*a))
			sort_three(a);
	else
		sort_turk(a, b, n);
}
