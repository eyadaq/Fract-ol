/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:07 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:28:42 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Writes an integer to the file descriptor specified by `fd`.
 *
 * The function handles negative numbers, printing a '-' sign 
 * before the digits. It also correctly handles the smallest 
 * 32-bit integer value (-2147483648) by printing it as a 
 * negative number. The function returns the count of 
 * characters written.
 *
 * @param n The integer to be written.
 * @param fd The file descriptor to which the integer is written.
 * @return The number of characters written.
 */

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		return (ft_putnbr_fd(147483648, fd) + 1);
	}
	else if (n > 9 && n <= 2147483647)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
