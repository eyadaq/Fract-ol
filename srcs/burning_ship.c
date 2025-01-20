/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:31:14 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/20 11:33:04 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void initialize_c_burning_ship(t_complex *c, int x, int y)
{
    c->re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
    c->im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
}

static int iterate_burning_ship(t_complex *z, t_complex c)
{
    int iter;
    double temp;
    double modulus;

    iter = -1;
    while (++iter < MAX_ITER)
    {
        modulus = pow(z->re, 2) + pow(z->im, 2);
        if (modulus > 4)
            break;
        temp = z->re;
        z->re = pow(fabs(z->re), 2) - pow(fabs(z->im), 2) + c.re;
        z->im = 2 * fabs(temp) * fabs(z->im) + c.im;
    }
    return iter;
}

void draw_burning_ship(t_data *data)
{
    int x;
    int y; 
    int iter;
    t_complex z;
    t_complex c;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            initialize_c_burning_ship(&c, x, y);
            z.re = 0;
            z.im = 0;
            iter = iterate_burning_ship(&z, c);
            if (iter < MAX_ITER)
                ft_mlx_pixel_put(data, x, y, 0x00FF00);
            else
                ft_mlx_pixel_put(data, x, y, 0x000000);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
























