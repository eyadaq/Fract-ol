/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 07:32:18 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:25:39 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Concatenates two strings, much like the standard function strcat.
 * It does, however, limit the amount of characters copied to the
 * destination string to a maximum of size - 1. This prevents buffer
 * overflows from occurring.
 *
 * The function returns the total length of the string that would have
 * been created if size was unlimited.
 *
 * Note that this function does not check if the source and destination
 * strings overlap.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param size The maximum number of characters to copy.
 * @return The total length of the string that would have been created.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	counter;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	counter = dst_len;
	i = 0;
	while (src[i] && counter < size - 1)
	{
		dst[counter] = src[i];
		counter++;
		i++;
	}
	dst[counter] = '\0';
	return (dst_len + src_len);
}
