/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/21 22:44:46 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void     draw_fractal(t_data *data, char *fractal_name)
{
    if (ft_strcmp(fractal_name, "mandelbrot") == 0)
    {
        draw_mandelbrot(data);
    }
    else if (ft_strcmp(fractal_name, "julia") == 0)
    {
        draw_julia(data);
    }
    else if (ft_strcmp(fractal_name, "burning_ship") == 0)
    {
        draw_burning_ship(data);
    }
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
	mlx_hook(data.win, 17, 0, &mlx_loop_end, data.mlx);
    mlx_loop(data.mlx);
    ft_destory(&data);
    return (0);
}


