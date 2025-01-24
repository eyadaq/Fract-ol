/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 03:05:20 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:28:48 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Converts an unsigned integer to its hexadecimal representation and
 * prints it to the standard output. The function uses either uppercase
 * or lowercase letters based on the given format specifier.
 *
 * @param hexa The unsigned integer to be converted to hexadecimal.
 * @param x The format specifier: 'c' for uppercase and 's' for lowercase.
 * @return The total number of characters printed.
 */

int	ft_puthexa(unsigned int hexa, char x)
{
	int		c;
	char	*digits;

	c = 0;
	if (x == 'c')
		digits = "0123456789ABCDEF";
	else if (x == 's')
		digits = "0123456789abcdef";
	else
		return (0);
	if (hexa >= 16)
		c += ft_puthexa(hexa / 16, x);
	c += ft_putchar_fd(digits[hexa % 16], 1);
	return (c);
}
