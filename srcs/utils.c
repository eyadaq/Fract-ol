/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:59:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/29 23:39:55 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_iterations_enhancer(int value)
{
	return ((0.3 * value) + 31);
}

int	ft_handle_key(int keycode, t_data *data)
{
	double move_step;

	move_step = 0.1 / data->zoom_factor;
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
	else 
		return (0);
	ft_draw_canves(data);
	return (0);
}


int ft_handle_mouse(int button, int x, int y, t_data *data)
{
    t_point mouse_before_zoom;
	t_point mouse_after_zoom;

    ft_calc_coordinate(data, &mouse_before_zoom, x, y);
    if (button == ZOOM_IN)
        data->zoom_factor *= 1.25;
    else if (button == ZOOM_OUT)
        data->zoom_factor *= 0.75;
    else
        return (0);
    ft_calc_coordinate(data, &mouse_after_zoom, x, y);
    data->center.x += (mouse_before_zoom.x - mouse_after_zoom.x);
    data->center.y += (mouse_before_zoom.y - mouse_after_zoom.y);
    data->max_iterations = ft_iterations_enhancer(data->max_iterations);
    ft_draw_canves(data);
    return (0);
}

t_complex	ft_complex_number_add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}

t_complex	ft_complex_number_squared(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}
