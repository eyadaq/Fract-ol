/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 06:34:50 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:24:00 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	is_in_set(char s, const char *set)
{
	while (*set)
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}

/**
 * Trims characters from the beginning and end of a string.
 *
 * This function removes all leading and trailing characters from the string
 * `s1` that are present in the string `set`. It returns a newly allocated
 * string with the trimmed content. If either `s1` or `set` is NULL, the
 * function returns NULL. The memory for the trimmed string is obtained with
 * `malloc` and should be freed by the caller.
 *
 * @param s1 The original string to be trimmed.
 * @param set The set of characters to be trimmed from the ends of `s1`.
 * @return The trimmed string, or NULL if memory allocation fails or if any 
 *         of the input strings is NULL.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trimmed == NULL)
		return (NULL);
	ft_memcpy(trimmed, &s1[start], (end - start));
	trimmed[end - start] = '\0';
	return (trimmed);
}
