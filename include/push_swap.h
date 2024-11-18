/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:21 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/18 06:45:38 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <../lib/libft/libft.h>
# include <limits.h>
# include <stdbool.h>

# define FORWARD 1
# define REVERSE 0

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// Error Handling
void				free_stack(t_node **stack);
void				error_indicator(t_node **a);
void				free_args(char **updated_args);
char				**parsing_arguments(int argc, char **argv);

// Stack initiation
void				init_stack_a(t_node **a, char **arguments);
void				init_stack_b(t_node **stack_a, t_node **stack_b);
void				sort_fine_tuning(t_node **a, t_node **b);
void				sort_turk(t_node **a, t_node **b, int size);
void				prep_for_push(t_node **stack, t_node *top_node,
						char stack_name);

// Nodes initiation
int					is_stack_dublicate(t_node *a, long num);
int					is_stack_ordered(t_node *a);

// Stack Utils
int					stack_size(t_node *a);
t_node				*find_last(t_node *last_node);
t_node				*find_max(t_node *a);
t_node				*find_min(t_node *stack);
void				set_cheapest(t_node *stack);
t_node				*get_cheapest(t_node *stack);
void				current_index(t_node *stack);
void				min_on_top(t_node **a);
void				init_nodes_a(t_node *a, t_node *b);
void				init_nodes_b(t_node *a, t_node *b);
void				min_on_top(t_node **stack);
void				execute_rotations(t_node **a, t_node **b,
						t_node *cheapest_node, int direction);

// Debugging
void				validate_stack(t_node *stack);

// Commands Functions
void				push(t_node **src, t_node **dst);
void				sort_three(t_node **a);
void				swap(t_node **head);
void				sa(t_node **a);
void				rotate(t_node **stack);
void				rev_rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);

#endif
