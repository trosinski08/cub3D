/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:04:29 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:51:42 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Adds an element to the end of the list.
 * 
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 * 
 * If the list is NULL, the new element becomes the start of the list.
 * Otherwise, it is added to the end of the list.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*counter;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	counter = ft_lstlast(*lst);
	counter -> next = new;
}
