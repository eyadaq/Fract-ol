/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:06:22 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:28:53 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * ft_putendl_fd:
 *	Outputs the string `s` to the file descriptor `fd`, followed by a newline.
 *
 *	@param s: The string to output.
 *	@param fd: The file descriptor to write to.
 *
 *	@return: The number of bytes written, including the newline character,
 *		      or 0 if the string is NULL.
 */

int	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
		return ((int)ft_strlen(s) + 1);
	}
	return (0);
}
