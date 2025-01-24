/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:25:05 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 02:06:23 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static double	ft_get_decimal(const char *decimal_str)
{
	double	decimal;
	int		len;

	if (!decimal_str || !*decimal_str)
		return (0);
	decimal = ft_atoi(decimal_str);
	len = ft_strlen(decimal_str);
	while (len-- > 0 && decimal > 1.0)
		decimal /= 10.0;
	return (decimal);
}

const char	*ft_skip_whitespaces(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	return (str);
}

const char	*ft_handle_sign(const char *str, int *isneg)
{
	*isneg = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		*isneg = -1;
		str++;
	}
	return (str);
}

/**
 * Converts a given string to a double value.
 *
 * The function takes a string as input and returns the corresponding double
 * value. It skips any leading whitespace, handles any sign character ('+' or
 * '-'), and interprets the number as a decimal value. If the number has a
 * decimal part, it extracts the decimal part and converts it to a double
 * value separately.
 *
 * If the input string is empty or NULL, the function returns 0.
 *
 * @param str the string to convert to a double value
 * @return the double value corresponding to the given string
 */
double	ft_atod(const char *str)
{
	double	num;
	double	decimal;
	int		isneg;
	char	**array;

	if (!str || !*str)
		return (0);
	str = ft_skip_whitespaces(str);
	str = ft_handle_sign(str, &isneg);
	num = 0;
	decimal = 0;
	if (*str == '.')
	{
		decimal = ft_get_decimal(++str);
		return (isneg * decimal);
	}
	array = ft_split(str, '.');
	if (!array)
		return (0);
	if (array[0] && *array[0] != '\0')
		num = ft_atoi(array[0]);
	if (array[1] && *array[1] != '\0')
		decimal = ft_get_decimal(array[1]);
	ft_free_double(array);
	return (isneg * (num + decimal));
}
