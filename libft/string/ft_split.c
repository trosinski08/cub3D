/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:14:17 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:18 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array of strings obtained by splitting
’s’ using the character ’c’ as a delimiter.
The array must end with a NULL pointer.
RETURN
The array of new strings resulting from the split. NULL if the allocation fails
*/

#include "../include/libft.h"

/**
 * Counts the number of occurrences of a delimiter in a string.
 *
 * @param str The input string.
 * @param delimiter The delimiter character.
 * @return The number of occurrences of the delimiter.
 */
static size_t	ft_delcounter(char const *str, char delimiter)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
		{
			counter++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
		else
			i++;
	}
	return (counter);
}

/**
 * Calculates the length of a substring until the 
 * delimiter character is encountered.
 *
 * @param str The input string.
 * @param delimiter The delimiter character.
 * @return The length of the substring.
 */
static size_t	str_len(char const *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != delimiter)
		i++;
	return (i);
}

/**
 * Frees the memory allocated for individual substrings and the string array.
 *
 * @param i The index of the current substring.
 * @param str_array The string array.
 */
static void	mem_free(size_t i, char **str_array)
{
	while (i > 0)
	{
		i--;
		free(str_array[i]);
	}
	free(str_array);
}

/**
 * Helper function for splitting the string into substrings
 * based on the delimiter.
 *
 * @param str The input string.
 * @param del The delimiter character.
 * @param str_array The string array to store the substrings.
 * @param dc The number of occurrences of the delimiter.
 * @return The string array containing the substrings.
 */
static char	**helper(char const *str, char del, char **str_array, size_t dc)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dc)
	{
		while (str[j] && str[j] == del)
			j++;
		str_array[i] = ft_substr(str, j, str_len(&str[j], del));
		if (!str_array[i])
			return (mem_free(i, str_array), (void *) NULL);
		while (str[j] && str[j] != del)
			j++;
		i++;
	}
	str_array[i] = NULL;
	return (str_array);
}

/**
 * Splits a string into an array of substrings based on a delimiter.
 *
 * @param str The input string.
 * @param delimiter The delimiter character.
 * @return The array of substrings.
 */
char	**ft_split(char const *str, char delimiter)
{
	char	**str_array;
	size_t	delcounter;

	if (!str)
		return (NULL);
	delcounter = ft_delcounter(str, delimiter);
	str_array = (char **)malloc(sizeof(char *) * (delcounter + 1));
	if (!str_array)
		return (NULL);
	str_array = helper(str, delimiter, str_array, delcounter);
	return (str_array);
}
