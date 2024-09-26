/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:53:43 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:20 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*
The strlcpy() and strlcat() functions copy and concatenate strings with the same 
input parameters and output result as snprintf(3).  They are designed to be 
safer, more consistent, and less error prone replacements for the easily misused 
functions strncpy(3) and strncat(3).
strlcpy() and strlcat() take the full size of the destination buffer and 
guarantee NUL-termination if there is room.  Note that room for the NUL 
should be included in dstsize.
strlcat() appends string src to the end of dst.  It will append at most dstsize
 - strlen(dst) - 1 characters.  It will then NUL-terminate, unless dstsize is 0
or the original dst string was longer than dstsize (in practice this should not
happen as it means that either dstsize is incorrect or that dst is not a proper
 string). If the src and dst strings overlap, the behavior is undefined.
 return
 strlcat() functions return the total length of the string they tried to create
*/

/**
 * Concatenates the source string to the destination string, ensuring that the
 * destination string is null-terminated and does not exceed the specified size.
 *
 * @param dest    The destination string.
 * @param source  The source string.
 * @param destsz  The size of the destination string buffer.
 * @return        The total length of the concatenated string.
 */
size_t	ft_strlcat(char *dest, const char *source, size_t destsz)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	while (dest[i1] != '\0' && i1 < destsz)
	{
		i1++;
	}
	while (source[i2] != '\0' && (i1 + i2 + 1) < destsz)
	{
		dest[i1 + i2] = source[i2];
		i2++;
	}
	if (i1 < destsz)
		dest[i1 + i2] = '\0';
	return (i1 + ft_strlen(source));
}
