/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:57:53 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/13 19:29:38 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	if(!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	if(!stack_a || !*stack_a)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void 	reverse_rotate_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}