/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:11:09 by marvin            #+#    #+#             */
/*   Updated: 2025/01/15 23:11:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	if (!stack)
		return (0);
	tmp = stack->next;
	min = stack->value;
	while (tmp != stack)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*temp;

	if (!stack)
		return (0);
	tmp = stack->next;
	max = stack->value;
	while (tmp != stack)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_pos(t_stack *stack, int value)
{
	t_stack	*tmp;
	int		i;

	if (!stack)
		return (0);
	if (stack->value == value)
		return (0);
	tmp = stack->next;
	i = 1;
	while (tmp != stack)
	{
		if (tmp->value == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	get_best_move()