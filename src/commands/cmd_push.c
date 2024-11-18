/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:31:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/18 03:24:10 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack, const char *stack_name);
/*void	push(t_node **src, t_node **dst)
{
	t_node	*pushed_node;

	if (!src || !*src) // Check if source stack is valid
		return ;
	pushed_node = *src;
	printf("[DEBUG]: Pushed node: %d\n", pushed_node->nbr);
	*src = (*src)->next;
	if (*src){
		printf("[DEBUG]: New src head: %p\n", *src ? *src : NULL);
		(*src)->prev = NULL;
	}
	pushed_node->prev = NULL;
	if (!*dst)
	{
		*dst = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = *dst;
		(*dst)->prev = pushed_node;
		*dst = pushed_node;
	}
	printf("[DEBUG]: Node %d moved to dst, new dst head: %d\n", pushed_node->nbr, (*dst)->nbr);
}*/
void push(t_node **src, t_node **dst)
{
    t_node *pushed_node;

    if (!src || !*src)
    {
        printf("[DEBUG]: Source stack is empty, cannot push\n");
        return;
    }

    pushed_node = *src;
	printf("[DEBUG]: Moving node %d from src to dst\n", pushed_node->nbr);
	printf("[!!!!!!DEBUG]: Address of src before update: %p\n", (void *)*src);

    *src = (*src)->next;
	printf("[DEBUG]: Address of src after update: %p\n", (void *)*src);

    if (*src){
		printf("[DEBUG]: New src head: %d\n", (*src)->nbr);
        (*src)->prev = NULL;
	}
	else 
		 printf("[DEBUG]: Src stack is now empty\n");

    pushed_node->next = NULL;
    pushed_node->prev = NULL;

    if (!*dst)
    {
        *dst = pushed_node;
        printf("[DEBUG]: Moved node %d to empty destination stack\n", pushed_node->nbr);
    }
    else
    {
        pushed_node->next = *dst;
        (*dst)->prev = pushed_node;
        *dst = pushed_node;
        printf("[DEBUG]: Moved node %d to destination stack, new head: %d\n", pushed_node->nbr, (*dst)->nbr);
    }
}
/*void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}*/

void pb(t_node **b, t_node **a)
{
    printf("[DEBUG]: Before pb\n");
    print_stack(*a, "Stack A");
    print_stack(*b, "Stack B");

    push(b, a);

    printf("[DEBUG]: After pb\n");
    print_stack(*a, "Stack A");
    print_stack(*b, "Stack B");

    ft_printf("pb\n");
}

void pa(t_node **a, t_node **b)
{
    printf("[DEBUG]: Before pa\n");
    print_stack(*a, "Stack A");
    print_stack(*b, "Stack B");

    push(a, b);

    printf("[DEBUG]: After pa\n");
    print_stack(*a, "Stack A");
    print_stack(*b, "Stack B");

    ft_printf("pa\n");
}


void print_stack(t_node *stack, const char *stack_name)
{
    printf("[DEBUG]: Printing %s\n", stack_name);
    if (!stack)
    {
        printf("[DEBUG]: %s is empty\n", stack_name);
        return;
    }
    while (stack)
    {
        printf("[DEBUG]: Node value: %d\n", stack->nbr);
        stack = stack->next;
    }
}