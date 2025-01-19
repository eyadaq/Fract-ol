/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:51:35 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/19 22:11:57 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 200
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define M_PI 3.14
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ESC_KEY 65307

# include "./libft/headers/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct s_data
{
	char	*addr;
	int		bpp;
	int		endian;
	int		line_length;
	void	*img;
	void	*mlx;
	void	*win;
}			t_data;

int			ft_handle_key(int keycode, t_data *data);
void		ft_perror(char *msg, int errno);
void		ft_destory(t_data *data);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_initialize(t_data *data);

#endif
