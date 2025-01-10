/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/11 01:27:12 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void			Mandelbrot()
{
	return ;
}
void			Julia()
{
	return ;
}

void			Snowflake()
{
	return ;
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

int		main(int argc, char **argv)
{
	t_fract		fractol;
	int			type;
	
	type = check_argument(argv[1]);
	if (argc != 2 || !(type))
		ft_perror("Please Choose one type of fractol : (Mandelbrot / Julia / Koch Snowflake)", 4242);
	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		ft_perror("MLX Initialization Failed", 1);
	
	
}
