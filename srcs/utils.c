/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:59:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/11 01:04:28 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_perror(const char *msg, int errno)
{
	if (errno == 4242)
	{
		ft_pustr_fd(msg, 2);
		exit(1);
	}
	else 
	{
		perror(msg);
		exit(errno);
	}
}