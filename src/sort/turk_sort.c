/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:10:55 by marvin            #+#    #+#             */
/*   Updated: 2025/01/15 23:10:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_move(t_stack *stack_a, t_stack *stack_b, int elem)
{
	int	count;
	int	index;

	count = 1;
	index = get_pos_el(stack_b, elem);
	if (index > 1 && index > (stack_length(stack_b) / 2))
		count += stack_length(stack_b) - index - 1;
	else if (index > 1 && index <= (stack_length(stack_b) / 2))
		count += index - 1;
	index = get_pos_place(stack_a, elem);
	if (index > 1 && index > (stack_length(stack_a) / 2))
		count += stack_length(stack_a) - index - 1;
	else if (index > 1 && index <= (stack_length(stack_a) / 2))
		count += index - 1;
	return (count);
}

int	opti_rotate(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	int	count;

	count = 0;
	if (pos_a <= stack_length(*a) / 2 && pos_b <= stack_length(*b) / 2)
	{
		while (count < pos_a && count < pos_b)
		{
			rotate_r(a, b);
			count++;
		}
	}
	else if (pos_a > stack_length(*a) / 2 && pos_b > stack_length(*b) / 2)
	{
		while (count < (stack_length(*a) - pos_a)
			&& count < (stack_length(*b) - pos_b))
		{
			reverse_rotate_r(a, b);
			count++;
		}
	}
	return (count);
}

static t_stack	*r_stack_a(t_stack *stack_a, int target_pos, int nbr_of_r)
{
	int	len;

	len = stack_length(stack_a);
	if (target_pos <= len / 2)
	{
		while (nbr_of_r < target_pos)
		{
			rotate_a(&stack_a);
			nbr_of_r++;
		}
	}
	else
	{
		while (nbr_of_r < (len - target_pos))
		{
			reverse_rotate_a(&stack_a);
			nbr_of_r++;
		}
	}
	return (stack_a);
}

void	rotate_and_push(t_stack **stack_a, t_stack **stack_b, int element)
{
	int		get_pos_a;
	int		get_pos_b;
	int		nbr_of_rotate;

	get_pos_a = get_pos_place(*stack_a, element);
	get_pos_b = get_pos_el(*stack_b, element);
	nbr_of_rotate = opti_rotate(stack_a, stack_b, get_pos_a, get_pos_b);
	while ((*stack_b)->value != element)
	{
		if (get_pos_b <= stack_length(*stack_b) / 2)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
	*stack_a = r_stack_a(*stack_a, get_pos_a, nbr_of_rotate);
	push_a(stack_a, stack_b);
}

void	turk_sort(t_stack **a, t_stack **b, t_cost *cost)
{
	int		best;

	while (*b)
	{
		best = get_best_move(*a, *b, cost);
		rotate_and_push(a, b, best);
	}
	b = NULL;
}
