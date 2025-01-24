/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:13:44 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:29:21 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Copies `len` bytes from the memory area `src` to memory area `dst`.
 * The memory areas may overlap: copying takes place as though the bytes
 * in `src` are first copied into a temporary array that does not overlap
 * `src` or `dst`, and the bytes are then copied from the temporary array
 * to `dst`.
 *
 * @param dst The destination memory area.
 * @param src The source memory area.
 * @param len The number of bytes to copy.
 * @return A pointer to the destination memory area `dst`.
 */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dp;
	const char	*sp;

	if (src == dst)
		return (dst);
	dp = (char *)dst;
	sp = (const char *)src;
	if (sp < dp && sp + len > dp)
		while (len--)
			*(dp + len) = *(sp + len);
	else
	{
		while (len--)
		{
			*dp = *sp;
			sp++;
			dp++;
		}
	}
	return (dst);
}
