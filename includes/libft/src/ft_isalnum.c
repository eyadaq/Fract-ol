/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:50:26 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:21:23 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Checks if the given character is an alphanumeric character.
 * @param x The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else if (x >= 'A' && x <= 'Z')
		return (1);
	else if (x >= 'a' && x <= 'z')
		return (1);
	else
		return (0);
}
