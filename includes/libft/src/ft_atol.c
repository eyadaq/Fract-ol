/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:20:02 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:20:37 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Converts a string to a long integer.
 *

	* @details This function takes a string and returns its long integer equivalent.
 * It ignores leading whitespace, and if the string starts with a + or - sign,
 * it will be recognized as a sign for the number. Otherwise, it will start
 * reading digits from the start of the string. If it encounters a non-digit
 * character, it will stop reading and return the number it has read so far.
 *
 * @param str the string to convert
 * @return the long integer equivalent of the string
 */
long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}
