/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:58:57 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:53:50 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The memcmp() function compares the first n bytes (each
interpreted as unsigned char) of the memory areas s1 and s2.
*/

/**
 * Compares the first n bytes of memory areas s1 and s2.
 *
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return 0 if the memory areas are equal, a positive value if s1
 * is greater than s2, or a negative value if s1 is less than s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	i = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (i < n)
	{
		if ((temp1[i] != temp2[i]))
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
