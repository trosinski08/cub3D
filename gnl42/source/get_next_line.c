/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:37:39 by trosinsk          #+#    #+#             */
/*   Updated: 2024/07/21 02:34:08 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/**
 * @file get_next_line_bonus.c
 * @brief Implementation of the get_next_line function with bonus features.
 */

/**
 * @brief Extracts the remaining line from a given string.
 *
 * This function takes a string as input and returns the remaining line 
 * after the first newline character. It uses the gnl_substr 
 * function to extract the remaining line.
 *
 * @param str The input string.
 * @return The remaining line after the first newline character, or 
 * NULL if an error occurs.
 */

/**
 * @brief Creates a new line from a given string.
 *
 * This function takes a string as input and returns a new line containing 
 * the characters up to and including the first newline character.
 * It uses the gnl_substr function to create the new line.
 *
 * @param str The input string.
 * @return The new line containing the characters up to and including 
 * the first newline character, or NULL if an error occurs.
 */

/**
 * @brief Reads the next line from a file descriptor.
 *
 * This function reads the next line from the file descriptor specified 
 * by `fd`.It uses a static array `str` to store the remaining content 
 * of each file descriptor. The function reads data from the file descriptor
 * in chunks of size `BUFFER_SIZE` and appends it to `str[fd]`. 
 * If a newline character is found in `str[fd]`, the function extracts 
 * the line using `line_maker` and updates `str[fd]` using `l_c`.
 * The function continues reading until the end of the file or 
 * an error occurs. If the end of the file is reached and there is 
 * remaining content in `str[fd]`, the function returns the remaining 
 * content as a line.
 *
 * @param fd The file descriptor to read from.
 * @return The next line from the file descriptor, or NULL if an error 
 * occurs or the end of the file is reached.
 */

char	*l_c(char *str)
{
	char	*rest_line;

	rest_line = gnl_substr(str, ((gnl_strchr(str, '\n') - str) + 1),
			gnl_strlen(str));
	if (!rest_line)
		return (NULL);
	return (free(str), rest_line);
}

char	*line_maker(char *str)
{
	char	*new_line;

	new_line = gnl_substr(str, 0, ((gnl_strchr(str, '\n') - str) + 1));
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	int			r;

	line = NULL;
	if ((fd < 0) || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(str[fd]), str[fd] = NULL, NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1 || (r == 0 && str[fd] == NULL))
			return (free(str[fd]), str[fd] = NULL, free(line), NULL);
		buff[r] = '\0';
		str[fd] = gnl_strjoin(str[fd], buff);
		if (gnl_strchr(str[fd], '\n'))
			return (line = line_maker(str[fd]), str[fd] = l_c(str[fd]), line);
	}
	if (r == 0 && *str[fd])
	{
		line = gnl_strdup(str[fd]);
		return (free(str[fd]), str[fd] = NULL, line);
	}
	return (free(str[fd]), str[fd] = NULL, free(line), NULL);
}
