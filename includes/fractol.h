/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:51:35 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/11 02:06:54 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1280
# define HEIGHT 720
# define MAX_ITER 500

# include <mlx.h>
# include <math.h>
#include "./libft/headers/libft.h"

typedef struct  s_complex
{
	double		re;
	double		im;
}			t_complex;
typedef struct  s_fract
{
    void 	*mlx;
    void 	*win;
    void 	*img;
    char 	*addr;
    int 	bpp;
    int 	line_length;
    int 	endian;
    double 	zoom;
    double 	offset_x;
    double 	offset_y;
	t_complex	c;
	
}				t_fract;

// void			Mandelbrot();

void			julia();

// void			Snowflake();

void			ft_perror(char *msg, int errno);

int 			get_color(int iter);

void 			put_pixel(t_fract *data, int x, int y, int color);

int 			handle_key(int keycode, t_fract *data);

#endif