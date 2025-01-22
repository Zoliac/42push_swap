/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:36 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/21 19:13:54 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(int *tab, int size, t_stack **stack_a, t_stack **stack_b)
{
	t_chunk	*chunk;
	t_cost	*cost;

	chunk = create_chunk(tab, size - 1);
	if (chunk == NULL)
		return ;
	chunk_sort(chunk, stack_a, stack_b);
	if (stack_length(*stack_a) == 3)
		case_three(stack_a);
	cost = malloc(sizeof(t_cost));
	if (cost == NULL)
		return ;
	turk_sort(stack_a, stack_b, cost);
	while ((*stack_a)->value != get_min(*stack_a))
	{
		if (get_pos_el(*stack_a, get_min
				(*stack_a)) <= stack_length(*stack_a) / 2)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	free(cost);
	free_all(stack_a, tab, chunk);
}
