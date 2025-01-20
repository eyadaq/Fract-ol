/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:28:15 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/18 23:04:26 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;
    
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void	ft_destory(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void        ft_initialize(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        ft_perror("MLX Initialization failed\n", 4242);
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
    if (!data->win)
        ft_perror("Window initialization failed\n", 4242);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img)
        ft_perror("Image creation failed\n", 4242);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
    if (!data->addr)
        ft_perror("Failed to fetch image address\n", 4242);
}