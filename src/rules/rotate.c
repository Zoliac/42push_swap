/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:57:32 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/21 19:02:17 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	rotate_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_r(t_stack **stack_a, t_stack	**stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
