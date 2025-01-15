/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:23:54 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/10 08:42:31 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stacks(t_stack **stack)
{
	t_stack	*pos;
	t_stack	*tmp;

	if (!*stack || !stack)
		return ;
	pos = *stack;
	tmp = NULL;
	(*stack)->prev->next = NULL;
	while (pos != NULL)
	{
		tmp = pos;
		pos = pos->next;
		free(tmp);
	}
}

void	free_array(int *tab)
{
	free(tab);
}

void	free_chunk(t_chunk *chunk)
{
	free(chunk);
}

void	free_all(t_stack **stack, int *tab, t_chunk *chunk)
{
	free_stacks(stack);
	free_array(tab);
	free_chunk(chunk);
}