/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:21 by ngoulios          #+#    #+#             */
/*   Updated: 2025/02/08 15:06:32 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../lib/libft/libft.h>
# include <limits.h>
# include <stdbool.h>

/** @def FORWARD
 *  @brief Macro representing forward rotation.
 */
# define FORWARD 1

/** @def REVERSE
 *  @brief Macro representing reverse rotation.
 */
# define REVERSE 0

/**
 * @struct s_node
 * @brief Structure representing a node in the stack.
 * 
 * Each node contains:
 * - An integer value.
 * - Its index in the stack.
 * - The push cost for optimal movement.
 * - Whether it is above the median.
 * - Whether it is the cheapest node to move.
 * - A pointer to its target node in the other stack.
 * - Pointers to the next and previous nodes in the stack.
 */
typedef struct s_node
{
	int				nbr; /**< The Integer value of the node. */
	int				index; /**< The index of the node in the stack. */
	int				push_cost; /**< The cost to push the node to the other stack */
	bool			above_median; /**< Flag indicating if the node is above median. */
	bool			cheapest; /**< Flag indicating if this node is the cheapest to move. */
	struct s_node	*target_node; /**< Pointer to the target node in the other stack. */
	struct s_node	*next; /**< Pointer to the next node in the stack. */
	struct s_node	*prev; /**< Pointer to the previous node in the stack. */
}					t_node;


/* ====================== Error Handling ====================== */

/**
 * @brief Frees the entire stack.
 * @param stack Pointer to the stack to be freed.
 */
void				free_stack(t_node **stack);

/**
 * @brief Prints an error message and frees stack A.
 * @param a Pointer to stack A.
 */
void				error_indicator(t_node **a);

/**
 * @brief Frees the argument list.
 * @param updated_args Argument list to free.
 */
void				free_args(char **updated_args);

/**
 * @brief Parses command-line arguments.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return A newly allocated array of arguments.
 */
char				**parsing_arguments(int argc, char **argv);

/**
 * @brief Frees a dynamically allocated argument array.
 * @param av_arr Argument array.
 * @param size Size of the array.
 */
void				free_av_arr(char **av_arr, int size);

/**
 * @brief Checks if a string is a valid integer.
 * @param arg The string to check.
 * @return 1 if valid, 0 otherwise.
 */
int					is_valid_integer(char *arg);

/* ====================== Stack Initialization ====================== */

/**
 * @brief Initializes stack A with parsed arguments.
 * @param a Pointer to stack A.
 * @param arguments Parsed arguments array.
 * @return 0 on success, 1 on failure.
 */
int					init_stack_a(t_node **a, char **arguments);

/**
 * @brief Determines and applies the appropriate sorting algorithm.
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void				sort_fine_tuning(t_node **a, t_node **b);

/**
 * @brief Implements the Turk Algorithm for sorting.
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param size Size of stack A.
 */
void				sort_turk(t_node **a, t_node **b, int size);

/**
 * @brief Prepares a node to be pushed to the top of a stack.
 * @param stack The stack containing the node.
 * @param top_node The node to move to the top.
 * @param stack_name The name of the stack ('a' or 'b').
 */
void				prep_for_push(t_node **stack, t_node *top_node,
						char stack_name);

/**
 * @brief Sorts three elements in stack A.
 * @param a Pointer to stack A.
 */
void				sort_three(t_node **a);

/* ====================== Stack Utilities ====================== */

/**
 * @brief Checks for duplicate values in the stack.
 * @param a Pointer to stack A.
 * @param num Number to check.
 * @return 1 if duplicate exists, 0 otherwise.
 */
int					is_stack_duplicate(t_node *a, long num);

/**
 * @brief Checks if the stack is already sorted.
 * @param a Pointer to stack A.
 * @return 1 if sorted, 0 otherwise.
 */
int					is_stack_ordered(t_node *a);

/**
 * @brief Gets the size of the stack.
 * @param a Pointer to stack A.
 * @return The size of the stack.
 */
int					get_stack_size(t_node *a);

/**
 * @brief Finds the last node in the stack.
 * @param last_node The starting node.
 * @return The last node in the stack.
 */
t_node				*find_last(t_node *last_node);

/**
 * @brief Finds the node with the maximum value in the stack.
 * @param a Pointer to the stack.
 * @return The node with the maximum value.
 */
t_node				*find_max(t_node *a);

/**
 * @brief Finds the node with the minimum value in the stack.
 * @param stack Pointer to the stack.
 * @return The node with the minimum value.
 */
t_node				*find_min(t_node *stack);

/**
 * @brief Marks the cheapest node to move.
 * @param stack Pointer to the stack.
 */
void				set_cheapest(t_node *stack);

/**
 * @brief Retrieves the cheapest node in the stack.
 * @param stack Pointer to the stack.
 * @return The cheapest node.
 */
t_node				*get_cheapest(t_node *stack);

/**
 * @brief Updates the index of each node.
 * @param stack Pointer to the stack.
 */
void				current_index(t_node *stack);

/**
 * @brief Moves the minimum value node to the top of stack A.
 * @param a Pointer to stack A.
 */
void				min_on_top(t_node **stack);

/**
 * @brief Calculates metadata for stack A.
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void				calculate_metadata_a(t_node *a, t_node *b);

/**
 * @brief Calculates metadata for stack B.
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void				calculate_metadata_b(t_node *a, t_node *b);

/**
 * @brief Executes the required rotations to align nodes optimally.
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param cheapest_node The node identified as the cheapest to move.
 * @param direction The direction of the rotation (FORWARD or REVERSE).
 */
void				execute_rotations(t_node **a, t_node **b, t_node *cheapest_node, int direction);

/**
 * @brief Cleans up allocated memory before exiting.
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param updated_args Pointer to the dynamically allocated argument array.
 */
void				cleanup(t_node **a, t_node **b, char **updated_args);

/**
 * @brief Moves a target node to the top of its stack.
 * @param stack Pointer to the stack.
 * @param target_node The node to move.
 * @param stack_name The name of the stack ('a' or 'b').
 */
void				move_to_top(t_node **stack, t_node *target_node, char stack_name);

/* ====================== Command Functions ====================== */

/* Stack Push Commands*/
void				push(t_node **src, t_node **dst);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);

/*Stack Swap Commands*/
void				swap(t_node **head);
void				sa(t_node **a);

/* Stack Rotate Commands*/
void				rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);

/* Stack Reverse Rotate Commands*/
void				rev_rotate(t_node **stack);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);


#endif
