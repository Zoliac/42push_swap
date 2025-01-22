/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:57:40 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/21 19:01:26 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_b || !stack_b)
		return ;
	node = *stack_b;
	if (node->next == node)
		*stack_b = NULL;
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		*stack_b = node->next;
	}
	if (!*stack_a)
	{
		node->next = node;
		node->prev = node;
	}
	else
		ft_stack_add_front(stack_a, node);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!*stack_a || !stack_a)
		return ;
	node = *stack_a;
	if (node->next == node)
		*stack_a = NULL;
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		*stack_a = node->next;
	}
	node->next = node;
	node->prev = node;
	if (!*stack_b)
		*stack_b = node;
	else
		ft_stack_add_front(stack_b, node);
	ft_printf("pb\n");
}
