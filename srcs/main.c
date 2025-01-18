/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/18 20:28:37 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"



#include <math.h>

void    draw_circle(t_data *data, int xCenter, int yCenter, int radius)
{
    float   step; 
    
    step = 0.01;

    for (float theta = 0; theta <= 2 * M_PI; theta += step)
    {
        int x = xCenter + (int)(radius * cos(theta));
        int y = yCenter + (int)(radius * sin(theta));

        my_mlx_pixel_put(data, x, y, 0xFFFFFF);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int main(void)
{
    t_data      data;
    
    initialize(&data);
    draw_circle(&data, WIDTH / 2, HEIGHT / 2, 100);
    mlx_loop(data.mlx);
    return (0);
}