/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:11:24 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:22:32 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Checks if the given character is an ASCII character.
 * @param x The character to check.
 * @return 1 if the character is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int x)
{
	if (0 <= x && x <= 127)
		return (1);
	else
		return (0);
}
