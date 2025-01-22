/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:43:45 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/21 19:00:26 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_overflows(char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if ((nbr * sign > 2147483647 || nbr * sign < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(char **args, int nb_args)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_args)
	{
		j = 0;
		if (is_valid(args[i]) == 0 || check_overflows(args[i]) == 0)
			return (ft_putstr_fd("Error\n", 2), 1);
		while (j < i)
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				return (ft_putstr_fd("Error\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	compare_numbers(char *str1, char *str2)
{
	long	num1;
	long	num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	return (num1 == num2);
}

int	is_valid(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i])
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	checker_arg(char **args, int nb_args)
{
	int	check;

	if (nb_args < 2 && is_valid(args[0]) == 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	check = ft_check(args, nb_args);
	return (check);
}
