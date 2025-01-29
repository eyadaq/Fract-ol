/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:48:48 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/29 23:23:28 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_calc_pixel_mandelbront(t_data *data, t_point point)
{
	t_complex	z;
	t_complex	c;
	int			iteration;

	z.im = 0.0;
	z.re = 0.0;
	c.im = point.y;
	c.re = point.x;
	iteration = 0;
	while (iteration < data->max_iterations)
	{
		z = ft_complex_number_add(ft_complex_number_squared(z), c);
		if (z.re * z.re + z.im * z.im > 4.0)
			return (iteration);
		iteration++;
	}
	return (0);
}

static int	ft_calc_pixel_julia(t_data *data, t_point point)
{
	t_complex	z;
	t_complex	c;
	int			iteration;

	z.im = point.y;
	z.re = point.x;
	c = data->julia_constant;
	iteration = 0;
	while (iteration < data->max_iterations)
	{
		z = ft_complex_number_add(ft_complex_number_squared(z), c);
		if (z.re * z.re + z.im * z.im > 4.0)
			return (iteration);
		iteration++;
	}
	return (0);
}

static int	ft_calc_pixel_burning_ship(t_data *data, t_point point)
{
	t_complex	z;
	t_complex	c;
	int			iteration;

	z.im = 0.0;
	z.re = 0.0;
	c.im = point.y;
	c.re = point.x;
	iteration = 0;
	while (iteration < data->max_iterations)
	{
		if (z.re < 0)
			z.re = -z.re;
		if (z.im < 0)
			z.im = -z.im;
		z = ft_complex_number_add(ft_complex_number_squared(z), c);
		if (z.re * z.re + z.im * z.im > 4.0)
			return (iteration);
		iteration++;
	}
	return (0);
}
static void burning_ship_color(t_color *color, double t)
{
	if (t < 0.5)
		{
			color->red = (int)(255 * t * 2);
			color->green = 0;
			color->blue = 0;
		}
		else if (t < 0.75)
		{
			color->red = 255;
			color->green = (int)(255 * (t - 0.5) * 4);
			color->blue = 0;
		}
		else
		{
			color->red = 255;
			color->green = 255;
			color->blue = (int)(255 * (t - 0.75) * 4);
		}
}
static void	ft_get_color(t_color *color, int iter, int max_iter, int fractal_type)
{
	double	t;

	if (iter == max_iter)
	{
		color->full_color = 0x000000;
		return ;
	}
	t = (double)iter / max_iter;
	if (fractal_type == JULIA && iter != max_iter)
	{
		color->red = (int)(255 * sin(0.3 * t + 0) * 0.5 + 0.5 * 255);
		color->green = (int)(255 * sin(0.3 * t + 2) * 0.5 + 0.5 * 255);
		color->blue = (int)(255 * sin(0.3 * t + 4) * 0.5 + 0.5 * 255);
	}
	else if (fractal_type == BURNING_SHIP && iter != max_iter)
		burning_ship_color(color, t);
	else if (fractal_type == MANDELBROT && iter != max_iter)
	{
		color->red = (int)(9 * (1 - t) * t * t * t * 255);
		color->green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		color->blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	color->full_color = (color->red << 16) | (color->green << 8) | color->blue;
}

void	ft_draw_canves(t_data *data)
{
	int		x;
	int		y;
	t_point	point;
	t_color	color;
	int		iter;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_calc_coordinate(data, &point, x, y);
			if (data->type == MANDELBROT)
				iter = ft_calc_pixel_mandelbront(data, point);
			else if (data->type == JULIA)
				iter = ft_calc_pixel_julia(data, point);
			else if (data->type == BURNING_SHIP)
				iter = ft_calc_pixel_burning_ship(data, point);
			ft_get_color(&color, iter, data->max_iterations, data->type);
			ft_mlx_pixel_put(data, x, y, color.full_color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
