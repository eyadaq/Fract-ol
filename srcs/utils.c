/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:59:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/27 21:18:01 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_iterations_enhancer(int value)
{
	return ((0.3 * value) + 30);
}

int	ft_handle_key(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		ft_destory(data);
		exit(1);
	}
	else if (keycode == ARROW_UP)
		data->center.y -= 0.1;
	else if (keycode == ARROW_DOWN)
		data->center.y += 0.1;
	else if (keycode == ARROW_RIGHT)
		data->center.x += 0.1;
	else if (keycode == ARROW_LEFT)
		data->center.x -= 0.1;
	else if (keycode == PLUS_KEY)
		data->max_iterations *= 1.5;
	else if (keycode == MINUS_KEY && data->max_iterations > 5)
		data->max_iterations *= 0.75;
	ft_draw_canves(data);
	return (0);
}



int	ft_handle_mouse(int button, int x, int y, t_data *data)
{
	if (button == ZOOM_IN)
	{
		ft_calc_coordinate(data, &data->center, x, y);
		data->center.y = -data->center.y;
		data->zoom_factor *= 1.1;
		data->max_iterations = ft_iterations_enhancer(data->max_iterations);
	}
	if (button == ZOOM_OUT)
	{
		data->zoom_factor *= 0.9;
		data->max_iterations = ft_iterations_enhancer(data->max_iterations);
	}
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
