/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 04:47:51 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:28:37 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * ft_putstr_printf:
 *	Prints a string to the standard output (fd = 1), and returns its length.
 *	If the string is NULL, "(null)" is printed instead.
 *
 *	@param ptr: the string to print
 *
 *	@return: the length of the printed string
 */
int	ft_putstr_printf(char *ptr)
{
	if (ptr != NULL)
		return (ft_putstr_fd(ptr, 1));
	else
		return (ft_putstr_fd("(null)", 1));
}
