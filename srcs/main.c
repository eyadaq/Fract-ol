/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/11 02:26:16 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void julia(t_fract
 *data) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            t_complex z = {
                .re = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom + data->offset_x,
                .im = (y - HEIGHT / 2.0) * 4.0 / WIDTH / data->zoom + data->offset_y
            };
            int iter = 0;
            while (z.re * z.re + z.im * z.im <= 4.0 && iter < MAX_ITER) {
                double temp = z.re * z.re - z.im * z.im + data->c.re;
                z.im = 2.0 * z.re * z.im + data->c.im;
                z.re = temp;
                iter++;
            }
            put_pixel(data, x, y, get_color(iter));
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int		check_argument(char *s)
{
	if (ft_strncmp(s, "Julia", 5) == 0)
	{
		return (1);
	}
	else if (ft_strncmp(s, "Mandelbrot",  10) == 0)
	{
		return (2);
	}
	else if (ft_strncmp(s, "Snowflake", 9) == 0)
	{
		return (3);
	}
	else 
		return (0);
}

int main(int argc, char **argv)
{
    t_fract data;
	int		type;
	
	type = check_argument(argv[1]);
    if (argc != 2 || !type)
        ft_perror("Invalid argument Choose one from these: Julia,Mandelbrot,Snowflake", 4242);
    data.mlx = mlx_init();
    if (!data.mlx)
        ft_perror("MLX initialization failed", 4242);
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, argv[1]);
    if (!data.win)
        ft_perror("Window creation failed", 4242);
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    if (!data.img)
        ft_perror("Image creation failed", 4242);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);
    if (!data.addr)
        ft_perror("Failed to get image address", 4242);
    data.zoom = 1.0;
    data.offset_x = 0.0;
    data.offset_y = 0.0;
    data.c.re = -0.7;
    data.c.im = 0.27015;
    if (type == 1)
        julia(&data);
    mlx_key_hook(data.win, handle_key, &data);
    mlx_loop(data.mlx);
    return (0);
}
