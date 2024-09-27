/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:32:50 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:23 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Returns a pointer to the last occurrence of the char 'c' in the string 's'.
 *
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the last occurrence
 * of 'c' in 's', or NULL if 'c' is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
