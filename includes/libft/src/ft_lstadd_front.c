/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:11:41 by eaqrabaw          #+#    #+#             */
/*   Updated: 2025/01/25 01:23:08 by eaqrabaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/**
 * Adds the element newnode at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param newnode The link to be added to the list.
 */

void	ft_lstadd_front(t_list **lst, t_list *newnode)
{
	newnode->next = *lst;
	*lst = newnode;
}
