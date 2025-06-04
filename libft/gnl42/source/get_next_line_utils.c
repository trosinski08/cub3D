/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:12:39 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/30 17:12:39 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	**get_buffer(void)
{
	static char	*buffer[OPEN_MAX];

	return (buffer);
}

void	clean_static_buffer(char **str, int fd)
{
	if (fd >= 0 && fd < OPEN_MAX && str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
	}
}

char	*line_maker(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*l_c(char *str)
{
	char	*res;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		return (NULL);
	}
	i++;
	res = ft_strdup(&str[i]);
	free(str);
	return (res);
}
