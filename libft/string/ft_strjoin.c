/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:57:42 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:20 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a new string, 
which is the result of the concatenation of ’s1’ and ’s2’.
*/

#include "../include/libft.h"

/**
 * Concatenates two strings and returns a new string.
 *
 * @param s1 The first string to be concatenated.
 * @param s2 The second string to be concatenated.
 * @return The concatenated string, or NULL if memory allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	d = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d)
	{
		return ((void *) '\0');
	}
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		d[i + j] = s2[j];
		j++;
	}
	d[i + j] = '\0';
	return (d);
}
