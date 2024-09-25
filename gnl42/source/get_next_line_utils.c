/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:36:56 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/28 00:54:26 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (free(s1), s1 = NULL, NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	if (!str)
		return (free(str), NULL);
	return (str);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*subs;

	i = 0;
	if (!s)
		return (0);
	if (start > gnl_strlen(s))
	{
		subs = malloc(sizeof(char) * 1);
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (gnl_strlen(s) - start < len)
		len = gnl_strlen(s) - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (start < gnl_strlen(s) && i < len && s[start])
	{
		subs[i++] = s[start++];
	}
	subs[i] = '\0';
	return (subs);
}

char	*gnl_strchr(char *s, int c)
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

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_strdup(char *s)
{
	int		i;
	char	*sdup;

	i = 0;
	sdup = (char *)malloc(gnl_strlen(s)+1);
	if (sdup == NULL)
		return (free(s), s = NULL, NULL);
	while (s[i] != '\0')
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
