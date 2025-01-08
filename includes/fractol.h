/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:51:35 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/08 18:53:24 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef FRACTOL_H
// # define FRACTOL_H

// #include "./libft/headers/libft.h"
// #include <mlx.h>
// #include <math.h>

// typedef struct s_fract
// {
	
// }	t_fract;
// #endif
#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_fract
{
	void 	*mlx;
	
}				t_fract;

void			Mandelbrot();
void			Julia();
void			Koch_Snowflake();
void			ft_perror(const char *msg, int errno);
#endif