/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:28:15 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/27 23:24:53 by eaqrabaw         ###   ########.fr       */
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

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_calc_coordinate(t_data *data, t_point *point, int x, int y)
{
	point->x = (x - WIDTH / 2.0) / data->zoom_factor + data->center.x;
	point->y = (y - HEIGHT / 2.0) / data->zoom_factor + data->center.y;
	//point->y = -point->y;
}

void	ft_destory(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->img != NULL)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_initialize(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_perror("MLX Initialization failed\n", 4242);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->win)
	{
		ft_perror("Window initialization failed\n", 4242);
		ft_destory(data);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		ft_perror("Image creation failed\n", 4242);
		ft_destory(data);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	if (!data->addr)
	{
		ft_perror("Failed to fetch image address\n", 4242);
		ft_destory(data);
	}
}
