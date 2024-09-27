/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:10:15 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:51:54 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Clears a linked list by deleting all of its nodes and freeing the memory.
 *
 * @param lst The address of a pointer to the first node of the list.
 * @param del The function used to delete the content of a node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*templ;

	if (*lst == NULL || del == NULL || lst == NULL)
	{
		return ;
	}
	while (lst != NULL && *lst != NULL)
	{
		templ = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = templ;
	}
}
