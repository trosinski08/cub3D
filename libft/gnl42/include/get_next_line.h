/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 06:56:35 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/29 17:53:16 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** ---------------------------------------------------------------------------
** get_next_line - Function for reading from file descriptors line by line
**
** This module provides functions to read content from a file descriptor
** one line at a time, with support for multiple file descriptors.
** The buffer size can be customized at compilation time.
** ---------------------------------------------------------------------------
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include "../../include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

/* Function declarations */
char	**get_buffer(void);
void	clean_static_buffer(char **str, int fd);
char	*line_maker(char *str);
char	*l_c(char *str);

/**
 * @brief Reads a line from a file descriptor
 * 
 * This function reads characters from the given file descriptor
 * until it encounters a newline character, end of file, or an error.
 * It returns a single line as a null-terminated string, including
 * the newline character if it exists.
 * 
 * @param fd The file descriptor to read from
 * @return A newly allocated string containing the line, or NULL if
 *         there's an error or nothing more to read
 */
char	*get_next_line(int fd);

/**
 * @brief Flushes all static buffers used by get_next_line
 * 
 * This function clears and frees all static buffers used by get_next_line.
 * Call this function before program exit to prevent memory leaks.
 */
void	flush_gnl_buffers(void);

/* Utility functions for get_next_line */
char	**get_buffer(void);
void	clean_static_buffer(char **str, int fd);
char	*line_maker(char *str);
char	*l_c(char *str);

#endif
