/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:10:41 by marvin            #+#    #+#             */
/*   Updated: 2025/01/15 23:10:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	cst_set_chunk(int size)
{
	if (size <= 200)
		return (4);
	else
		return (8);
}

t_chunk	*create_chunk(int *tab, int size)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	chunk->values = tab;
	chunk->middle = size / 2;
	chunk->cst_set = cst_set_chunk(size);
	chunk->chunk_size = size / chunk->cst_set;
	chunk->start = chunk->middle - chunk->chunk_size;
	chunk->end = chunk->middle + chunk->chunk_size;
	chunk->total_size = size;
	return (chunk);
}
