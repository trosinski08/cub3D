/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:32:11 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:53:38 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The memchr() function scans the initial n bytes of the memory
area pointed to by s for the first instance of c.  Both c and the
bytes of the memory area pointed to by s are interpreted as
unsigned char.
*/
/**
 * Searches for the first occurrence of a character in a block of memory.
 *
 * @param s     Pointer to the block of memory to search.
 * @param c     Character to be located.
 * @param n     Number of bytes to search.
 * @return      Pointer to the first occurrence of the character,
 * or NULL if the character is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;
	int		i;
	int		t;

	i = 0;
	t = n;
	temp = (char *)s;
	while (i < t)
	{
		if (temp[i] == (char)c)
			return ((char *)&temp[i]);
		i++;
	}
	return (0);
}
