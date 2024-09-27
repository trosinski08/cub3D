/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:45:24 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/21 22:55:40 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

/*
DESCRIPTION         top
       The memset() function fills the first n bytes of the memory area
       pointed to by s with the constant byte c.
RETURN VALUE         top
       The memset() function returns a pointer to the memory area s.
*/

/**
 * Fills a block of memory with a specified value.
 *
 * @param s     Pointer to the memory block to be filled.
 * @param c     Value to be set. The value is passed as an int, but the function
 *              fills the block of memory using the unsigned char conversion of
 *              this value.
 * @param n     Number of bytes to be set to the value.
 * @return      Pointer to the memory block.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char *)s;
	printf("S: %d\n", c);
	write(1, &c, 1);
	while (i < n)
	{
		temp[i] = c;
		printf("S: %d\n", temp[i]);
		i++;
	}
	return (s);
}
