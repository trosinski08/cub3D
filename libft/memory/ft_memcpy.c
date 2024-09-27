/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:41:06 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:54:09 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
DESCRIPTION        
The memcpy() function copies n bytes from memory area src to
memory area dest.  The memory areas must not overlap.  Use
memmove(3) if the memory areas do overlap.
RETURN VALUE
The memcpy() function returns a pointer to dest.
*/

/**
 * Copies a block of memory from a source address to a destination address.
 *
 * @param dest The pointer to the destination address
 * where the memory will be copied to.
 * @param src The pointer to the source address
 * where the memory will be copied from.
 * @param n The number of bytes to be copied.
 * @return A pointer to the destination address.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (!dest && !src)
		return (0);
	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dest);
}
