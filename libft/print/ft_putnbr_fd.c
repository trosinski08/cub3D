/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:29:59 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:55:05 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Writes the integer 'n' to the file descriptor 'fd'.
 *
 * If 'n' is equal to -2147483648, it writes "-2" to 'fd' and then recursively
 * calls ft_putnbr_fd with the value 147483648.
 *
 * If 'n' is negative, it writes a "-" character to 'fd', converts 'n' to its
 * absolute value, and then recursively calls ft_putnbr_fd with the absolute
 * value of 'n'.
 *
 * If 'n' is greater than 9, it recursively calls ft_putnbr_fd with 'n' divided
 * by 10 and 'fd' as arguments, and then writes the remainder of 'n' divided by
 * 10 plus '0' to 'fd'.
 *
 * If none of the above conditions are met, it writes 'n' plus '0' to 'fd'.
 *
 * @param n The integer to be written to 'fd'.
 * @param fd The file descriptor to write 'n' to.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
		ft_putnbr_fd(n, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}
