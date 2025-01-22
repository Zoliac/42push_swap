/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:50:07 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/21 18:58:52 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**handle_args(int argc, char **argv, int *size)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		*size = 0;
		while (args[*size])
			(*size)++;
	}
	else
	{
		*size = argc - 1;
		args = malloc(sizeof(char *) * (*size + 1));
		if (!args)
			return (NULL);
		i = -1;
		while (++i < *size)
			args[i] = ft_strdup(argv[i + 1]);
		args[i] = NULL;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
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
	if (is_sorted(&stack_a, size) == 0)
		return (free_stacks(&stack_a), free_array(tab), 0);
	push_swap(tab, size, &stack_a, &stack_b);
	return (0);
}
