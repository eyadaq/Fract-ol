/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:24:12 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:25:06 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Scans the initial `n` bytes of the memory area pointed to by `s`
 * for the first instance of `c`. Both `c` and the bytes of the memory
 * area pointed to by `s` are interpreted as unsigned char.
 *
 * @param s The pointer to the memory area to be scanned.
 * @param c The value to be searched in the memory area.
 * @param n The number of bytes to be scanned in the memory area.
 * @return A pointer to the matching byte, or NULL if the byte is not found
 *         within the first `n` bytes.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				counter;
	const unsigned char	*src;

	src = (const unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (src[counter] == (unsigned char)c)
			return ((void *)(src + counter));
		counter++;
	}
	return (NULL);
}
