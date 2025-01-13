/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listaddfrond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 06:54:00 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/10 08:42:36 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stack_add_front(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return ;
	}
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}