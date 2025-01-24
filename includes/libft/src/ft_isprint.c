/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:21:44 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:22:46 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * ft_isprint - Checks if a character is printable
 * @n: The character to be checked
 *
 * Return: 1 if the character is printable, 0 otherwise
 */

int	ft_isprint(int n)
{
	if (n >= ' ' && n <= '~')
		return (1);
	else
		return (0);
}
