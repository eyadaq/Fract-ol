/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/07 23:25:13 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int 		check_argument(char *s)
{
	if (ft_strcmp() == 0)
	{
		return (1);
	}
	else if (ft_strcmp() == 0)
	{
		return (1);
	}
	else if (ft_strcmp() == 0)
	{
		return (1);
	}
	else 
		return (0);
}

int	main(int argc, char **argv)
{
	t_fract		*fractol;
	
	if (argc != 2 || !check_argument(argv[1]))
	{
		perror("Please Choose one type of fractol : (Mandelbrot / Julia / Koch Snowflake)");
		return (1);
	}
}