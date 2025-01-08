/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:54:19 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/08 18:53:00 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_perror(const char *msg, int errno)
{
	perror(msg);
	exit(errno);
}

int 		check_argument(char *s)
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

int	main(int argc, char **argv)
{
	t_fract		*fractol;
	int			type;
	
	type = check_argument(argv[1]);
	if (argc != 2 || !(type))
		ft_perror("Please Choose one type of fractol : (Mandelbrot / Julia / Koch Snowflake)", 1);
}