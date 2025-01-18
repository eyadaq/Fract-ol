/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:51:35 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/18 20:29:47 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 200
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ESC_KEY 65307
# define M_PI 3.14

# include <mlx.h>
# include <math.h>
# include "./libft/headers/libft.h"

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    
}               t_data;


void			ft_perror(char *msg, int errno);

void	        my_mlx_pixel_put(t_data *data, int x, int y, int color);

void            initialize(t_data *data);


#endif