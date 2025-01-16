/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:36 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/16 01:57:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(int *tab, int size, t_stack **stack_a, t_stack **stack_b)
{
	t_chunk	*chunk;
	t_cost	cost;

	chunk = ft_create_chunk(tab, size);
	if (chunk == NULL)
		return ;
	chunk_sort(chunk, stack_a, stack_b);
	if (stack_length(*stack_a) == 3)
		case_three(stack_a);
	cost = malloc(sizeof(t_cost));
	if (cost == NULL)
		return ;
	turk_sort(stack_a, stack_b, cost);
	while ((*a)->value != get_min(*a))
	{
		if (get_pos_el(*a, get_min(*a)) <= stack_length(*a) / 2)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	free(cost)
	free_all(stack_a, tab, chunk);
}
