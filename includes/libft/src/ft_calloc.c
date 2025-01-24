/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:13:21 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:21:01 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Allocates memory for an array of 'count' elements, each of 'size' bytes,
 * and initializes all its bits to zero.
 *
 * @param count The number of elements to allocate.
 * @param size The size of each element.
 *
 * @return A pointer to the allocated memory, or NULL if the allocation failed.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}
