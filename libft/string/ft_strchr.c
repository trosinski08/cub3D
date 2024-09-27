/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:47:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:19 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
The strchr() function returns a pointer to the first occurrence
of the character c in the string s.
*/

/**
 * The ft_strchr() function locates the first occurrence of the char 'c'
 * (converted to a char) in the string 's'. The search includes the
 * terminating null character.
 *
 * @param s The string to be searched.
 * @param c The character to be located.
 * @return A pointer to the first occurrence of the char 'c' in the string 's',
 *         or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
