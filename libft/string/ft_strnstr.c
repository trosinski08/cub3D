/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:57 by trosinsk          #+#    #+#             */
/*   Updated: 2025/05/26 00:02:00 by GitHub Copilot   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *hstack, const char *ndle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ndle[0] == '\0')
		return ((char *)hstack);
	if (len == 0 && ndle[0] != '\0')
		return (NULL);
	i = 0;
	while (hstack[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && ndle[j] != '\0' && hstack[i + j] == ndle[j])
			j++;
		if (ndle[j] == '\0')
			return ((char *)hstack + i);
		i++;
	}
	return (NULL);
}
