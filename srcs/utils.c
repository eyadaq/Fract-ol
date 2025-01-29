/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:59:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/30 00:37:47 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_handle_key(int keycode, t_data *data)
{
	double move_step;

	move_step = 30 / data->zoom_factor;
	if (keycode == ESC_KEY)
	{
		ft_destory(data);
		exit(1);
	}
	else if (keycode == ARROW_UP)
		data->center.y -= move_step;
	else if (keycode == ARROW_DOWN)
		data->center.y += move_step;
	else if (keycode == ARROW_RIGHT)
		data->center.x += move_step;
	else if (keycode == ARROW_LEFT)
		data->center.x -= move_step;
	ft_draw_canves(data);
	return (0);
}


int ft_handle_mouse(int button, int x, int y, t_data *data)
{
    t_point mouse_before_zoom;
	t_point mouse_after_zoom;

    ft_calc_coordinate(data, &mouse_before_zoom, x, y);
    if (button == ZOOM_IN)
	{
		data->max_iterations += 5;
        data->zoom_factor *= 1.25;
	}
    else if (button == ZOOM_OUT)
	{
		data->max_iterations -= 5;
        data->zoom_factor *= 0.75;
	}
    else
        return (0);
    ft_calc_coordinate(data, &mouse_after_zoom, x, y);
    data->center.x += (mouse_before_zoom.x - mouse_after_zoom.x);
    data->center.y += (mouse_before_zoom.y - mouse_after_zoom.y);
    ft_draw_canves(data);
    return (0);
}

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
void	ft_get_color(t_color *color, int iter, int max_iter, int fractal_type)
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
		color->red   = (int)(9 * (1 - t) * t * t * t * 255);
    	color->green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    	color->blue  = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
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