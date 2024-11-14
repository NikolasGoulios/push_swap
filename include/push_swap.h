/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:21 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/14 21:53:18 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdbool.h>
# include <limits.h>
# include <../lib/libft/libft.h>


// Dexa Comments to the functions for Github and different for Vogsphare causse Norminette 

typedef struct s_node 			//A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; 			//The number to sort
	int					index; 			//The number's position in the stack
	int					push_cost; 		//How many commands in total
	bool				above_median; 	//Used to calculate `push_cost`
	bool				cheapest; 		//The node that is the cheapest to do commands
	struct s_node		*target_node; 	//The target node of a node in the opposite stack
	struct s_node		*next; 			//A pointer to the next node
	struct s_node		*prev; 			//A pointer to the previous node
}	t_node; 						//The "shortened name", "t_stack_node". `t_` for type


// Error Handling 
void	free_stack(t_node **stack);
void	error_indicator(t_node **a);
char 	**parsing_arguments(int argc, char **argv);


// Stack initiation
void	init_stack_a(t_node **a, char **arguments);
void	short_initialize(t_node **a, t_node *b);

// Nodes initiation
int		is_stack_dublicate(t_node *a);
int		is_stack_ordered(t_node *a);

// Stack Utils
int		ft_stacksize(t_node *a);
long	ft_atol(const char *str);
t_node	*find_last(t_node *last_node);
void print_stack(t_node *stack); //Debug

//Commands Functions
void	swap(t_node **head);
void	sa(t_node **a);

#endif
