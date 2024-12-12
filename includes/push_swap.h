/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:21:17 by lpatin            #+#    #+#             */
/*   Updated: 2024/12/11 17:21:46 by lpatin           ###   ########.fr       */
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

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}			t_move;

#endif