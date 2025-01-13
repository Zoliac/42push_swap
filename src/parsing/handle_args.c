/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:36:00 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/10 08:42:14 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char 	**handle_args(int argc, char **argv, int *size)
{
	char	**args;
	int		i;

	if(argc == 2)
	{
		args - ft_split(argv[1], ' ');
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
