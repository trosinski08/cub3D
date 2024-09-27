/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:11:39 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:51:57 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Returns the last element of a linked list.
 *
 * @param lst The head of the linked list.
 * @return The last element of the linked list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*counter;

	counter = lst;
	if (!lst)
		return (NULL);
	if (counter->next == NULL)
	{
		return (counter);
	}
	while (counter->next != NULL)
	{
		counter = counter->next;
	}
	return (counter);
}
