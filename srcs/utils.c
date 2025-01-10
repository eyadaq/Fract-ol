/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:59:38 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/11 02:04:54 by eaqrabaw         ###   ########.fr       */
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

int 	get_color(int iter)
{
    if (iter == MAX_ITER)
        return (0x000000);
    return (0xFFFFFF * iter / MAX_ITER);
}

void 	put_pixel(t_fract *data, int x, int y, int color) {
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

int handle_key(int keycode, t_fract *data)
{
    if (keycode == 53) // Escape key
        exit(0);
    else if (keycode == 126) // Up arrow key
        data->offset_y -= 0.1 / data->zoom;
    else if (keycode == 125) // Down arrow key
        data->offset_y += 0.1 / data->zoom;
    else if (keycode == 123) // Left arrow key
        data->offset_x -= 0.1 / data->zoom;
    else if (keycode == 124) // Right arrow key
        data->offset_x += 0.1 / data->zoom;
    else if (keycode == 69) // Plus key
        data->zoom *= 1.1;
    else if (keycode == 78) // Minus key
        data->zoom /= 1.1;

    // Redraw the fractal with updated parameters
    julia(data);
    return (0);
}