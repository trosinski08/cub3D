/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:29:25 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:22 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Compares two strings up to a specified number of characters.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if 
 * the first n characters of s1 are found, respectively, to be less than, 
 * to match, or be greater than the first n characters of s2.
 */
int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	int				i;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	while (temp1[i] != '\0' && temp2[i] == temp1[i] && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	if (n < 0)
		return (-2);
	return (temp1[i] - temp2[i]);
}
