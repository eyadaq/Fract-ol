/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:59:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/22 00:38:02 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// ZOOM AND MOVEING IN THE IMAGE PLUS THE COLORS 

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

int    ft_handle_key(int  keycode, t_data *data)
{
    if (keycode == ESC_KEY)
    {
        ft_destory(data);
        exit(1);
    }

	printf("%d\n", keycode);

	if (keycode == 65362) //up
	{
		data->center.y -= 0.1;
	} 
	if (keycode == 65364) //down
	{
		data->center.y += 0.1;
	} 
	if (keycode == 65363) //right
	{
		data->center.x += 0.1;
	} 
	if (keycode == 65361) //left
	{
		data->center.x -= 0.1;
	}

	if (keycode == 61)
		data->max_iterations *= 1.5;
	if (keycode == 45 && data->max_iterations > 5)
		data->max_iterations *= 0.75;
	
	draw_canves(data);

	return (0);
}

int ft_handle_mouse(int button, int x, int y, t_data *data)
{
	
	// printf("%d %d\n", x, y);

	if (button == 4)
	{
		calc_coordinate(data, &data->center, x, y);
		data->center.y = -data->center.y;
		data->zoom_factor *= 1.1;
		data->max_iterations += 1;
	}
	if (button == 5)
	{
		data->zoom_factor *= 0.9;
		data->max_iterations -= 1;
	}

	printf("%d\n", data->max_iterations);

	draw_canves(data);

	return (0);
}