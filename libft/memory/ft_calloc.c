/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:58:40 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:10 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*
The calloc(), function allocate memory. The allocated memory is aligned 
such that it can be used for any data type, including AltiVec- and 
SSE-related types. The malloc() function allocates size bytes of memory 
and returns a pointer to the allocated memory.
The calloc() function contiguously allocates enough space for count objects that 
are size bytes of memory each and returns a pointer to
the allocated memory.  The allocated memory is filled with bytes of value zero.
*/

/**
 * Allocates memory for an array of elements and initializes them to 0.
 *
 * @param counter The number of elements to allocate memory for.
 * @param sizer The size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t counter, size_t sizer)
{
	char	*m;
	int		memcap;

	if (counter > 2147483647 || sizer > 2147483647)
		return (NULL);
	memcap = counter * sizer;
	m = (char *)malloc(memcap);
	if (!m)
	{
		return ((void *)0);
	}
	else
	{
		ft_bzero(m, memcap);
	}
	return (m);
}
