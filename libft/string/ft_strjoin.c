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

#include "../include/libft.h" // For ft_strlen, malloc, NULL
// #include <stdlib.h> // For malloc, NULL if not in libft.h (usually is)

/**
 * Concatenates two strings and returns a new string.
 *
 * @param s1 The first string to be concatenated. Can be NULL.
 * @param s2 The second string to be concatenated. Can be NULL.
 * @return The concatenated string, or NULL if memory allocation fails.
 *         If s1 and s2 are both NULL or effectively empty,
 *         returns an empty string.
 */

static char	*join_helper(char *d, const char *s2, size_t i, size_t j)
{
	while (s2[j])
	{
		d[i + j] = s2[j];
		j++;
	}
	return (d);
}

static size_t	str_checker(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	i;
	size_t	j;
	size_t	s2_len;

	s2_len = str_checker(s2);
	d = (char *)malloc(str_checker(s1) + s2_len + 1);
	if (!d)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (i < str_checker(s1))
		{
			d[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2)
		d = join_helper(d, s2, i, j);
	d[i + s2_len] = '\0';
	return (d);
}
