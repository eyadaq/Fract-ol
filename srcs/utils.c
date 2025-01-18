/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:59:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/18 20:27:50 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_perror(char *msg, int errno)
{
	if (errno == 4242)
	{
		ft_putstr_fd(msg, 2);
		exit(1);
	}
	else 
	{
		perror(msg);
		exit(errno);
	}
}

void        initialize(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        ft_perror("MLX Initialization failed", 10);
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Window1");
    if (!data->win)
        ft_perror("Window initialization failed", 11);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img)
        ft_perror("Image creation failed", 12);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
    if (!data->addr)
        ft_perror("Failed to fetch image address", 13);
}

