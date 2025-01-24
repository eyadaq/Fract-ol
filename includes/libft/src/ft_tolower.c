/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:18:51 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:23:41 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * The ft_tolower function converts an uppercase letter to a lowercase letter.
 *
 * This function takes a single character x as an argument and returns the
 * lowercase equivalent if x is an uppercase letter, otherwise it returns x as
 * is.
 *
 * @param x the character to convert to lowercase
 *
 * @returns the lowercase equivalent of x if x is uppercase, otherwise x
 */
int	ft_tolower(int x)
{
	if (x >= 'A' && x <= 'Z')
		return (x + 32);
	else
		return (x);
}
