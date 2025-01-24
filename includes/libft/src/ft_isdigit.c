/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:28:30 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:22:39 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * @brief Checks if the given character is a digit.
 *
 * @details This function determines if the input character is a numeric
 * digit ('0' to '9'). It returns the character itself if it is a digit,
 * or 0 otherwise.
 *
 * @param c The character to check.
 * @return The character if it is a digit, otherwise 0.
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}
