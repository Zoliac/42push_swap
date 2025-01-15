/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lenght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:52:05 by marvin            #+#    #+#             */
/*   Updated: 2025/01/15 23:52:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_length(t_stack *stack)
{
	t_stack	*pos;
	int		count;

	if (!stack)
		return (0);
	pos = stack->next;
	count = 1;
	while (pos != stack)
	{
		count++;
		pos = pos->next;
	}
	return (count);
}
