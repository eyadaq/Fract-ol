/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:21:05 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:28:36 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Prints an unsigned integer to the standard output.
 *
 * @param digit the unsigned integer to print.
 * @return the number of characters printed.
 */
int	ft_putunsigned(unsigned int digit)
{
	int	c;

	c = 0;
	if (digit >= 10)
		c += ft_putunsigned(digit / 10);
	c += ft_putchar_fd(((digit % 10) + '0'), 1);
	return (c);
}
