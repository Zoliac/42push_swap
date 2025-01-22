/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:50:05 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/21 19:00:53 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*pos;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	pos = *stack;
	while (pos->next != *stack && pos -> next)
		pos = pos -> next;
	pos -> next = new;
	new -> prev = pos;
}

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*init_stacks(char **args, int nb_args, t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*first;
	t_stack	*last;
	int		i;

	i = 0;
	first = NULL;
	last = NULL;
	while (i < nb_args)
	{
		node = ft_new_node(ft_atoi(args[i]));
		if (!node)
			return (NULL);
		ft_stack_add_back(stack_a, node);
		if (!first)
			first = node;
		last = node;
		i++;
	}
	first -> prev = last;
	last -> next = first;
	*stack_a = first;
	return (first);
}
