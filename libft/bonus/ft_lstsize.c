/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:11:57 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:56:32 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Counts the number of elements in a linked list.
 *
 * @param lst The pointer to the first node of the linked list.
 * @return The number of elements in the linked list.
 */
int	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*templ;

	size = 0;
	if (lst == NULL)
		return (size);
	templ = lst;
	while (templ != NULL)
	{
		templ = templ -> next;
		size ++;
	}
	return (size);
}
