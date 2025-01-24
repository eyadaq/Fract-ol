/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 02:06:24 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:29:07 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_format(char c, va_list list)
{
	if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(list, int), 1));
	else if (c == 's')
		return (ft_putstr_printf(va_arg(list, char *)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(list, unsigned int), 's'));
	else if (c == 'X')
		return (ft_puthexa(va_arg(list, unsigned int), 'c'));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (c == 'p')
		return (ft_putptr(va_arg(list, void *)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(list, unsigned int)));
	else if (c == '%')
		return (ft_putchar_fd(c, 1));
	else
		return (-1);
}

/**
 * Prints a formatted string to stdout.
 *
 * This function takes a format string as the first argument and
 * any number of arguments as additional arguments. The format string
 * contains format specifiers that determine how the arguments are
 * printed. The supported format specifiers are:
 *
 *   %i, %d: int
 *   %s: char *
 *   %x, %X: unsigned int
 *   %c: char
 *   %p: void *
 *   %u: unsigned int
 *   %%%
 *
 * The function returns the number of characters printed. If an error
 * occurs, the function returns -1.
 *
 * @param var The format string.
 * @param ... Any number of arguments.
 * @return The number of characters printed.
 */
int	ft_printf(const char *var, ...)
{
	va_list	list;
	int		i;
	int		c;
	int		counter;

	counter = 0;
	va_start(list, var);
	i = 0;
	while (var[i])
	{
		c = i + 1;
		if (var[i] == '%')
		{
			c = ft_format(var[++i], list);
			if (c == -1)
				return (-1);
			counter += c;
		}
		else
			counter += ft_putchar_fd(var[i], 1);
		i++;
	}
	va_end(list);
	return (counter);
}
