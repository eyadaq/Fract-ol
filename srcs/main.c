/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/22 00:35:48 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	complex_number_add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}

t_complex	complex_number_squared(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}

int calc_pixel_mandelbront(t_data *data, t_point point)
{
    t_complex z;
    t_complex c;

    z.im = 0.0;
    z.re = 0.0;

    c.im = point.y;
    c.re = point.x;

    // printf("%Lf, %Lf\n", c.re, c.im);

    int iteration = 0;
    while (iteration < data->max_iterations)
    {

        z = complex_number_add(complex_number_squared(z), c);

        if (z.re * z.re + z.im * z.im > 4.0)
            return iteration;
        
        iteration++;
    }
    return 0;
}




void calc_coordinate(t_data *data, t_point *point, int x, int y)
{
    point->x = (x - WIDTH / 2.0) / data->zoom_factor + data->center.x;
    point->y = (y - HEIGHT / 2.0) / data->zoom_factor + data->center.y;

    point->y = -point->y;
}

// -400 / 100, 400 /100

void draw_canves(t_data *data)
{
    int x;
    int y;
    t_point point;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            calc_coordinate(data, &point, x, y);
            int iter = calc_pixel_mandelbront(data, point);
            unsigned int color = iter * 10;

            int red = 255 - iter * 2;
            int green = 150;
            int blue = 200;

            if (iter)
                color = red << 16 | green << 8 | blue;
            ft_mlx_pixel_put(data, x, y, color);
        }
    }

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);    
}


static void     draw_fractal(t_data *data, char *fractal_name)
{
    if (ft_strcmp(fractal_name, "mandelbrot") == 0)
    {
        draw_canves(data);
    }
    // else if (ft_strcmp(fractal_name, "julia") == 0)
    // {
    //     draw_julia(data);
    // }
    // else if (ft_strcmp(fractal_name, "burning_ship") == 0)
    // {
    //     draw_burning_ship(data);
    // }
    else
    {
        ft_perror("Invalid fractal name. Available fractals: mandelbrot, julia, burning_ship\n", 4242);
    }
}

int main(int argc, char *argv[])
{
    t_data      data;

    if (argc != 2)
        ft_perror("Usage: ./fractol <fractal_name>\nAvailable fractals: mandelbrot, julia, burning_ship\n", 4242);
    ft_initialize(&data);
    
    draw_fractal(&data, argv[1]);

    mlx_key_hook(data.win, ft_handle_key, &data);
    mlx_mouse_hook(data.win, ft_handle_mouse, &data);

	mlx_hook(data.win, 17, 0, &mlx_loop_end, data.mlx);
    mlx_loop(data.mlx);
    ft_destory(&data);
    return (0);
}


