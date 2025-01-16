/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:49:16 by lpatin            #+#    #+#             */
/*   Updated: 2025/01/16 01:10:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_chunk	*ft_create_chunk(int *tab, int size)
{
	t_chunk	*chunk;
	
	chunk = malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	chunk->values = tab;
	chunk->middle = (size / 2);
	chunk->cst_set = ft_wich_cst(size);
	chunk->chunk_size = size / chunk->cst_set;
	chunk->start = chunk->middle - chunk->chunk_size;
	chunk->end = chunk->middle + chunk->chunk_size;
	chunk->total_size = size;
	return (chunk);
}
