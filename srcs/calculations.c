/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:34:28 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/30 00:42:14 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

void	ft_calc_coordinate(t_data *data, t_point *point, int x, int y)
{
	point->x = (x - WIDTH / 2.0) / data->zoom_factor + data->center.x;
	point->y = (y - HEIGHT / 2.0) / data->zoom_factor + data->center.y;
}
