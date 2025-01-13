/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:21:17 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/10 08:41:47 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"

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

void		ft_swap(int *a, int *b);
void		ft_quick_sort(int *tab, int start, int end);
void		ft_free_stack(t_stack **stack);
void		ft_stack_add_back(t_stack **stack, t_stack *new);
int			is_sorted(t_stack **stack, int nbr_of_args);
int			*ft_init_array(char **args, int nb_of_args);
int			check_overflows(char *str);
int			ft_cut(int *tab, int start, int end);
int			ft_check(char **args, int nb_args);
int			is_valid(char *arg);
int			checker_arg(char **args, int nb_args);
static char	**handle_args(int argc, char **argv, int *size);
t_stack		*init_stacks(int **args, int nb_args, t_stack **stack_a);
t_stack 	*ft_new_node(int value);

//Algorithm functions

void		push_swap(int *tab, int size, t_stack **stack_a, t_stack **stack_b);

//Rules

void		push_a(t_stack **stack_a, t_stack **stack_b);

//Utils

void		free_stacks(t_stack **stack);
void		free_array(int *tab);
void		free_chunk(t_chunk *chunk);
void		ft_stack_add_front(t_stack **lst, t_stack *new);
void		free_all(t_stack **stack, int *tab, t_chunk *chunk);
t_chunk		*ft_create_chunk(int *tab, int size);

#endif