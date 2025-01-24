/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:04:57 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:28:39 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * ft_putstr_fd:
 *	Outputs the string `s` to the file descriptor `fd`.
 *
 *	@param s: The string to output.
 *	@param fd: The file descriptor to write to.
 *
 *	@return: The number of bytes written, or 0 if the string is NULL.
 */
int	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		return ((int)write(fd, s, ft_strlen(s)));
	return (0);
}
