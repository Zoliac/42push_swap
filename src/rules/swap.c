/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:58:03 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/21 19:02:27 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!top || !*top || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	swap_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	if ((!stack_b || !*stack_b || !(*stack_b)->next)
		&& (!stack_a || !*stack_a || !(*stack_a)->next))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
