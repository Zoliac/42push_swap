/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:36 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/10 08:42:39 by lpatin           ###   ########.fr       */
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
	
}
