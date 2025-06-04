/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:37:39 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/30 18:15:39 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*process_remaining_buffer(char **str, int fd)
{
	char	*line;

	if (!str[fd] || *str[fd] == '\0')
	{
		clean_static_buffer(str, fd);
		return (NULL);
	}
	line = ft_strdup(str[fd]);
	if (!line)
	{
		clean_static_buffer(str, fd);
		return (NULL);
	}
	free(str[fd]);
	str[fd] = NULL;
	return (line);
}

static char	*process_buffer_with_newline(char **str, int fd)
{
	char	*line;

	if (ft_strchr(str[fd], '\n'))
	{
		line = line_maker(str[fd]);
		if (!line)
			return (clean_static_buffer(str, fd), NULL);
		str[fd] = l_c(str[fd]);
		return (line);
	}
	return (NULL);
}

static char	*read_and_process(char **str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*temp;
	int		r;

	r = read(fd, buff, BUFFER_SIZE);
	if (r == -1)
		return (clean_static_buffer(str, fd), NULL);
	if (r == 0 && str[fd] == NULL)
		return (NULL);
	buff[r] = '\0';
	temp = ft_strjoin(str[fd], buff);
	if (!temp)
		return (clean_static_buffer(str, fd), NULL);
	if (str[fd])
		free(str[fd]);
	str[fd] = temp;
	return (process_buffer_with_newline(str, fd));
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		**buffer;

	buffer = get_buffer();
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (clean_static_buffer(buffer, fd), NULL);
	if (read(fd, 0, 0) == -1)
		return (clean_static_buffer(buffer, fd), NULL);
	while (1)
	{
		temp = read_and_process(buffer, fd);
		if (temp)
			return (temp);
		if (!buffer[fd] || buffer[fd][0] == '\0')
			break ;
	}
	return (process_remaining_buffer(buffer, fd));
}

void	flush_gnl_buffers(void)
{
	char	**buffer;
	int		fd;

	buffer = get_buffer();
	fd = 0;
	while (fd < OPEN_MAX)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		fd++;
	}
}
