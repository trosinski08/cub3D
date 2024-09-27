/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:29:53 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 19:15:33 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * Writes a character to the specified file descriptor.
 *
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
