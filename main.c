/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:50:07 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/15 22:54:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char	**args;
	int		size;
	int		*tab;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	args = handle_args(argc, argv, &size);
	if (!args)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (checker_arg(args, size) != 0)
		return (needfree(args, size), 1);
	tab = ft_init_array(args, size);
	init_stacks(args, size, &stack_a);
	needfree(args, size);
	if(is_sorted(&stack_a, size) == 0)
		return (free_stack(&stack_a), free_array(tab), 0);
	push_swap(tab, size, &stack_a, &stack_b);
	return (0);
}