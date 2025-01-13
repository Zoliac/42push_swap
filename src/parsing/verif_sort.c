/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:21:24 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/10 08:42:20 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack **stack, int nbr_of_args)
{
	t_stack	*pos;
	int		i;

	i = 1;
	pos = *stack;
	while (i < nbr_of_args)
	{
		if (pos->value > pos->next->value)
			return (1);
		pos = pos->next;
		i++;
	}
	return (0);
}
