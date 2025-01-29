/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/30 00:33:05 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.zoom_factor = 100;
	data.max_iterations = 30;
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
