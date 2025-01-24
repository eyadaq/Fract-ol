/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:40:51 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:29:14 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Fills the first `n` bytes of the memory area pointed to by `s` with
 * the constant byte `c`.
 *
 * @param s The pointer to the memory area to be filled.
 * @param c The value to be set in the memory area.
 * @param n The number of bytes to fill with the value `c`.
 * @return A pointer to the memory area `s`.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str++ = (unsigned char)c;
	}
	return (s);
}
