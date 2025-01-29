/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/29 23:26:32 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_small_text(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

static void	ft_draw_fractal(t_data *data, char *fractal_name)
{
	ft_small_text(fractal_name);
	if (ft_strcmp(fractal_name, "mandelbrot") == 0)
	{ 
		ft_initialize(data);
		data->type = MANDELBROT;
		ft_draw_canves(data);
	}
	else if (ft_strcmp(fractal_name, "julia") == 0)
	{
		ft_initialize(data);
		data->type = JULIA;
		ft_draw_canves(data);
	}
	else if (ft_strcmp(fractal_name, "burning_ship") == 0)
	{
		ft_initialize(data);
		data->type = BURNING_SHIP;
		ft_draw_canves(data);
	}
	else
	{
		ft_perror("Invalid Input:mandelbrot, julia[x][y], burning_ship\n", 4242);
	}
}

static void	ft_validate_input(int argc, char *argv[], t_data *data)
{
	if (argc == 4)
	{
		
		data->julia_constant.im = ft_atod(argv[2]);
		data->julia_constant.re = ft_atod(argv[3]);
		ft_draw_fractal(data, argv[1]);
	}
	else if (argc == 2)
	{ 	
		data->julia_constant.im = 0.27015;
		data->julia_constant.re = -0.7;
		ft_draw_fractal(data, argv[1]);
	}
	else
		ft_perror("Invalid Input:mandelbrot, julia[x][y], burning_ship\n", 4242);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.zoom_factor = 100;
	data.max_iterations = 300;
	data.center.x = 0.0;
	data.center.y = 0.0;
	data.julia_constant.re = 0.0;
	data.julia_constant.im = 0.0;
	ft_validate_input(argc, argv, &data);
	mlx_key_hook(data.win, ft_handle_key, &data);
	mlx_mouse_hook(data.win, ft_handle_mouse, &data);
	mlx_hook(data.win, 17, 0, &mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);
	ft_destory(&data);
	return (0);
}
