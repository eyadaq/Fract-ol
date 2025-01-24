/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 06:44:35 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:24:08 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Locates the last occurrence of the character `c` in the string `s`.
 *
 * @param s The string in which to search.
 * @param c The character to locate, converted to a `char`.
 * @return A pointer to the last occurrence of `c` in the string `s`,
 *         or NULL if the character is not found.
 */

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
