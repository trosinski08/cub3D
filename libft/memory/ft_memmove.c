/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:43:39 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:54:24 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
       void *memmove(void dest[.n], const void src[.n], size_t n);
DESCRIPTION         top
       The memmove() function copies n bytes from memory area src to
       memory area dest.  The memory areas may overlap: copying takes
       place as though the bytes in src are first copied into a
       temporary array that does not overlap src or dest, and the bytes
       are then copied from the temporary array to dest.
RETURN VALUE         top
       The memmove() function returns a pointer to dest.
*/
/** Copies a block of memory from a source address to a destination
 * address, handling overlapping memory regions correctly.
 *
 * @param dst   Pointer to the destination address where the memory
 * will be copied to.
 * @param src   Pointer to the source address from where the memory
 * will be copied.
 * @param len   Number of bytes to be copied.
 * @return      Pointer to the destination address.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!len || dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest > source && dest < source + len)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
