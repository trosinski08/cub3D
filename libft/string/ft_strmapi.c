/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:36:22 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:22 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Applies the function ’f’ to each character of the string ’s’, and passing 
its index as first argument to create a new string (with malloc(3)) 
resulting from successive applications of ’f’.
*/

/**
 * Applies a function to each character of a string and creates a new string
 * with the results.
 *
 * @param str The input string.
 * @param func The function to apply to each character.
 * @return The new string created by applying the function to each character.
 *         Returns NULL if memory allocation fails.
 */
char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	char			*mapstr;
	unsigned int	i;

	i = 0;
	mapstr = (char *)malloc(sizeof(char) * (ft_strlen(str)) + 1);
	if (!mapstr)
		return ((void *)0);
	while (str[i] != '\0')
	{
		mapstr[i] = func(i, str[i]);
		i++;
	}
	mapstr[i] = '\0';
	return (mapstr);
}
