/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:51:35 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/22 00:15:52 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 400
# define HEIGHT 400
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

typedef struct s_complex
{
	long double		im;
	long double		re;
}				t_complex;

typedef struct s_point
{
    long double x;
    long double y;
} t_point;

typedef struct s_data
{
	char	*addr;
	int		bpp;
	int		endian;
	int		line_length;
	void	*img;
	void	*mlx;
	void	*win;

	int max_iterations;
	long double zoom_factor;
	t_point center;

}			t_data;

int			ft_handle_key(int keycode, t_data *data);
int ft_handle_mouse(int button, int x, int y, t_data *data);


void		ft_perror(char *msg, int errno);
void		ft_destory(t_data *data);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_initialize(t_data *data);
void		draw_mandelbrot(t_data *data);
void 		draw_julia(t_data *data);
void 		draw_burning_ship(t_data *data);


void calc_coordinate(t_data *data, t_point *point, int x, int y);


void draw_canves(t_data *data);

#endif
