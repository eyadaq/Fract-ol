/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/20 11:31:43 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(void)
{
    t_data      data;

    ft_initialize(&data);
    draw_julia(&data);
    mlx_key_hook(data.win, ft_handle_key, &data);
	mlx_hook(data.win, 17, 0, &mlx_loop_end, data.mlx);
    mlx_loop(data.mlx);
    ft_destory(&data);
    return (0);
}



























