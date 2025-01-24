/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:39:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:26:10 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Locates the first occurrence of `c` in the string `s`.
 *
 * @param s The string in which to search.
 * @param c The character to locate, converted to a `char`.
 * @return A pointer to the first occurrence of `c` in the string `s`,
 *         or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == (char)c)
			return ((char *)(s + x));
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)(s + x));
	return (NULL);
}
