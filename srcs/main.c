/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 02:37:13 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void     ft_draw_fractal(t_data *data, char *fractal_name)
{
    if (ft_strcmp(fractal_name, "mandelbrot") == 0)
    {
        data->type = MANDELBROT;
        ft_draw_canves(data);
    }
    else if (ft_strcmp(fractal_name, "julia") == 0)
    {
        data->type = JULIA;
        ft_draw_canves(data);
    }
    else if (ft_strcmp(fractal_name, "burning_ship") == 0)
    {
        data->type = BURNING_SHIP;
        ft_draw_canves(data);
    }
    else
    {
        ft_destory(data);
        ft_perror("Invalid fractal name. Available fractals: mandelbrot, juliajulia [x][y], burning_ship\n", 4242);
    }
}

void         ft_validate_input(int argc,char  *argv[], t_data *data) 
{
    if (argc == 2 && ft_strcmp(argv[1], "julia") == 0)
    {
        ft_destory(data);
        ft_perror("Invalid fractal name. Available fractals: mandelbrot, julia julia [x][y], burning_ship\n", 4242);
    }
    else if (argc == 2)
        ft_draw_fractal(data, argv[1]);
    else if (argc == 4) 
    {
        data->julia_x = ft_atod(argv[2]);
        data->julia_y = ft_atod(argv[3]);
        ft_draw_fractal(data, argv[1]);
    }
    else
    {
        ft_destory(data);
        ft_perror("Invalid fractal name. Available fractals: mandelbrot, julia [x][y], burning_ship\n", 4242);
    }
}

int main(int argc, char *argv[])
{
    t_data      data;
    
    data->zoom_factor = 100;
    data->max_iterations = 15;
    data->center.x = 0.0;
    data->center.y = 0.0;
    data->julia_x = 0.0;
    data->julia_y = 0.0;
    ft_initialize(&data);
    ft_validate_input(argc, argv, &data);
    mlx_key_hook(data.win, ft_handle_key, &data);
    mlx_mouse_hook(data.win, ft_handle_mouse, &data);
	mlx_hook(data.win, 17, 0, &mlx_loop_end, data.mlx);
    mlx_loop(data.mlx);
    ft_destory(&data);
    return (0);
}


