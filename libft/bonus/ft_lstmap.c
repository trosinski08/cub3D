/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:08:51 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:51:57 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
definiuje zmienne, sprawdzam czy funkcje zostaly przekazane,dla danego w tej 
iteracji elementu listy dzialam funkcja, dla przetworzonego elementu towrze 
nowa liste i alokuje pamiec, jesli alokacja sie nie powiedzie usuwam element,
zwalniam pamiec, zwracam null, jesli sie powiedzie dodaj element jako ostatni 
do listy, iteruje do nastepnego elementu zwracam nowa liste
*/
#include "../include/libft.h"
/**
 * Applies the function `f` to each element of the linked list `lst` and creates
 * a new list with the results. The `del` function is used to delete the content
 * of any node in case of an allocation failure.
 *
 * @param lst The linked list to iterate over.
 * @param f The function to apply to each element.
 * @param del The function used to delete the content of a node.
 * @return The new list with the results of applying `f` to each element, or NULL
 * if an allocation failure occurs.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*new_content;
	t_list	*new_node;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
