/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:39:22 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/10 08:42:05 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_cut(int *tab, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[end]);
	return (i + 1);
}

void	ft_quick_sort(int *tab, int start, int end)
{
	int	pivot;

	if(start < end)
	{
		pivot = ft_cut(tab, start, end);
		ft_quick_sort(tab, start, pivot - 1);
		ft_quick_sort(tab, pivot + 1, end);
	}
}

int *ft_init_array(char **args, int nb_of_args)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * nb_of_args);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nb_of_args)
	{
		tab[i] = ft_atoi(args[i]);
		i++;
	}
	ft_quick_sort(tab, 0, nb_of_args - 1);
	return (tab);
}
