/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:57 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:22 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * The ft_strnstr() function locates the first occurrence of
 * the null-terminated string needle in the string haystack, where not more
 * than len characters are searched. Characters that appear after a '\0' char
 * are not searched. Since the ft_strnstr() function is a FreeBSD specific API,
 * it should only be used when portability is not a concern.
 *
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the beginning of the located substring, or NULL
 * if the substring is not found. If needle is the empty string,
 * the return value is always haystack itself.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while ((haystack[i] != '\0') && i <= len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *) haystack + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
