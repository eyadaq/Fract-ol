/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:51:35 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 02:56:09 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 200
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ESC_KEY 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define PLUS_KEY 61
# define MINUS_KEY 45

# include "./libft/headers/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct s_complex
{
	long double		im;
	long double		re;
}					t_complex;

typedef struct s_color
{
	int				blue;
	int				green;
	int				red;
	unsigned int	full_color;
}					t_color;

typedef struct s_point
{
	long double		x;
	long double		y;
}					t_point;

typedef struct s_data
{
	char			*addr;
	int				bpp;
	int				endian;
	int				line_length;
	int				max_iterations;
	int				type;
	long double		zoom_factor;
	t_complex		julia_constant;
	t_point			center;
	void			*img;
	void			*mlx;
	void			*win;
}					t_data;

int					ft_calc_pixel_burning_ship(t_data *data, t_point point);
int					ft_calc_pixel_julia(t_data *data, t_point point);
int					ft_calc_pixel_mandelbront(t_data *data, t_point point);
int					ft_handle_key(int keycode, t_data *data);
int					ft_handle_mouse(int button, int x, int y, t_data *data);
int					ft_iterations_enhancer(int value);
t_complex			ft_complex_number_add(t_complex z1, t_complex z2);
t_complex			ft_complex_number_squared(t_complex z);
void				ft_calc_coordinate(t_data *data, t_point *point, int x,
						int y);
void				ft_calc_coordinate(t_data *data, t_point *point, int x,
						int y);
void				ft_destory(t_data *data);
void				ft_draw_canves(t_data *data);
void				ft_get_color(t_color *color, int iter);
void				ft_initialize(t_data *data);
void				ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void				ft_perror(char *msg, int errno);
#endif
