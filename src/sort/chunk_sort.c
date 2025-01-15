/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:10:44 by marvin            #+#    #+#             */
/*   Updated: 2025/01/15 23:10:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	move(t_chunk *chunk, t_stack *elem)
{
	int	i;

	i = chunk->start;
	while (i <= chunk->end)
	{
		if(chunk->values[i] == elem->value)
		{
			if (i < chunk->middle)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

void	update_chunk(t_chunk *chunk, t_stack **stack)
{
	if (value_in_chunk(chunk, stack) == 0)
	{
		if (chunk->start - chunk->chunk_size < 0)
			chunk->start -= chunk->start;
		else
			chunk->start -= chunk->chunk_size;
		if (chunk->end + chunk->chunk_size > chunk->total_size)
			chunk->end = chunk->total_size - 1;
		else
			chunk->end += chunk->chunk_size;
	}
}

void	chunk_sort(t_chunk *chunk, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*elem;
	int		test;

	if (!chunk || !stack_a || !stack_b)
		return ;
	while (stack_length(*stack_a) > 3)
	{
		elem = *stack_a;
		test = move(chunk, elem);
		if (test == 1)
			push_b(stack_a, stack_b);
		else
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
		update_chunk(chunk, stack_a);
	}
}