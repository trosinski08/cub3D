/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:32:07 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/29 01:10:47 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
specified in ’set’ removed from the beginning and the end of the string.
STRCHR
The strchr() function returns a pointer to the first occurrence
of the character c in the string s.
*/

/**
 * @brief Trims the specified characters from the beginning and end of a string.
 * 
 * This function trims the characters specified in the 'set' parameter from
 * the beginning and end of the 's1' string. It allocates memory for
 * the trimmed string and copies the trimmed portion of the original string
 * into the new memory block.
 * 
 * @param s1 The string to trim.
 * @param set The characters to trim from the string.
 * @return A new string with the specified characters trimmed,
 * or NULL if memory allocation fails.
 */
char	*ft_strtrim(char const	*s1, char const	*set)
{
	int		i;
	int		j;
	char	*trims;

	trims = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
		{
			j--;
		}
		trims = (char *) malloc (sizeof (char) * (j - i + 1));
		if (trims)
			ft_strlcpy(trims, &s1[i], j - i + 1);
		else
			return (NULL);
	}
	free((char *)s1);
	return (trims);
}
