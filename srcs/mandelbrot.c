/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:31:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/20 11:32:26 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void initialize_c(t_complex *c, int x, int y)
{
    c->re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
    c->im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
}

static int iterate_mandelbrot(t_complex *z, t_complex c)
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
        z->re = pow(z->re, 2) - pow(z->im, 2) + c.re;
        z->im = 2 * temp * z->im + c.im;
    }
    return iter;
}

void draw_mandelbrot(t_data *data)
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
            initialize_c(&c, x, y);
            z.re = 0;
            z.im = 0;
            iter = iterate_mandelbrot(&z, c);
            if (iter < MAX_ITER)
                ft_mlx_pixel_put(data, x, y, 0x00FF00);
            else
                ft_mlx_pixel_put(data, x, y, 0x000000);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

















