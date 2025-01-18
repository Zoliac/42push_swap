/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:21:17 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/18 19:31:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../src/libft/includes/libft.h"

typedef struct s_stack
{
	int 			value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_cost
{
	int		total;
	int		best;
}			t_cost;

typedef struct s_chunk
{
	int	*values;
	int	start;
	int	end;
	int	chunk_size;
	int	middle;
	int	cst_set;
	int	total_size;
}			t_chunk;

//Parsing Functions

void			ft_swap(int *a, int *b);
int				ft_cut(int *tab, int start, int end);
void			ft_quick_sort(int *tab, int start, int end);
int				*ft_init_array(char **args, int nb_of_args);
int				check_overflows(char *str);
int				ft_check(char **args, int nb_args);
int				is_valid(char *arg);
int				checker_arg(char **args, int nb_args);
void			ft_stack_add_back(t_stack **stack, t_stack *new);
int				compare_numbers(char *str1, char *str2);
void			ft_free_stack(t_stack **stack);
t_stack 		*ft_new_node(int value);
t_stack			*init_stacks(char **args, int nb_args, t_stack **stack_a);
int				is_sorted(t_stack **stack, int nbr_of_args);

//Rules

void			push_b(t_stack **stack_a, t_stack **stack_b);
void			push_a(t_stack **stack_a, t_stack **stack_b);
void			reverse_rotate(t_stack **stack);
void			reverse_rotate_a(t_stack **stack_a);
void 			reverse_rotate_b(t_stack **stack_b);
void			reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);
void			rotate(t_stack **stack);
void			rotate_a(t_stack **stack_a);
void			rotate_b(t_stack	**stack_b);
void			rotate_r(t_stack	**stack_a, t_stack	**stack_b);
void			swap(t_stack **top);
void			swap_a(t_stack **stack_a);
void			swap_b(t_stack **stack_b);
void			swap_s(t_stack **stack_a, t_stack **stack_b);

//Algorithm functions

int				value_in_chunk(t_chunk *chunk, t_stack **stack);
int				move(t_chunk *chunk, t_stack *elem);
void			update_chunk(t_chunk *chunk, t_stack **stack);
void			chunk_sort(t_chunk *chunk, t_stack **stack_a, t_stack **stack_b);
int				cst_set_chunk(int size);
t_chunk			*create_chunk(int *tab, int size);
int				get_min(t_stack *stack);
int				get_max(t_stack *stack);
int				get_pos_el(t_stack *stack, int value);
int				get_pos_place(t_stack *stack, int value);
int				get_best_move(t_stack *stack_a, t_stack *stack_b, t_cost *cost);
void			push_swap(int *tab, int size, t_stack **stack_a, t_stack **stack_b);
int				count_move(t_stack *stack_a, t_stack *stack_b, int elem);
int				opti_rotate(t_stack **a, t_stack **b, int pos_a, int pos_b);
void			rotate_and_push(t_stack **stack_a, t_stack **stack_b, int element);
void			turk_sort(t_stack **a, t_stack **b, t_cost *cost);

//Utils

void			ft_stack_add_front(t_stack **lst, t_stack *new);
void			case_three(t_stack **stack);
void			case_two(t_stack **stack);
void			free_stacks(t_stack **stack);
void			free_array(int *tab);
void			free_chunk(t_chunk *chunk);
void			free_all(t_stack **stack, int *tab, t_chunk *chunk);
void			needfree(char **result, int i); 
t_chunk			*create_chunk(int *tab, int size);
int				stack_length(t_stack *stack);

#endif