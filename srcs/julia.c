/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:31:24 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/20 11:31:37 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void initialize_z(t_complex *z, int x, int y)
{
    z->re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
    z->im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
}

static int iterate_julia(t_complex *z, t_complex c)
{
    int iter;
    double temp;
    double  modulus;

    iter = -1;
    while (++iter < MAX_ITER)
    {
        modulus = pow(z->re, 2) + pow(z->im, 2);
        if (modulus > 4)
            break;
        temp = z->re;
        z->re = pow(z->re, 2) - pow(z->im, 2) + c.re;
        z->im = 2 * temp * z->im + c.im;
    }
    return iter;
}

void draw_julia(t_data *data)
{
    int x;
    int y;
    int iter;
    t_complex z;
    t_complex c;

    c.im = 0.5;
    c.re = 0.7;
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            initialize_z(&z, x, y);
            iter = iterate_julia(&z, c);
            if (iter < MAX_ITER)
                ft_mlx_pixel_put(data, x, y, 0x00FF00);
            else
                ft_mlx_pixel_put(data, x, y, 0x000000);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}










