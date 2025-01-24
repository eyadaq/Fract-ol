/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:04:12 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:28:59 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * ft_putchar_fd:
 *	Outputs the character `c` to the file descriptor `fd`.
 *
 *	@param c: The character to output.
 *	@param fd: The file descriptor to write to.
 *
 *	@return: The number of bytes written, or 0 or -1 on error.
 */
int	ft_putchar_fd(char c, int fd)
{
	return ((int)write(fd, &c, 1));
}
