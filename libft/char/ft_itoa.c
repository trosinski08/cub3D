/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:47:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:05 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @file ft_itoa.c
 * @brief This file contains the implementation of the ft_itoa function.
 * 
 * The ft_itoa function converts an integer into a string representation.
 * 
 * @param num The integer to be converted.
 * @return The string representation of the integer.
 */
static int	signcounter(int num)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		return (1);
	}
	if (num < 0)
	{
		num = -num;
		len += 1;
	}
	if (num == -2147483648)
	{
		return (11);
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	unsigned int	len;
	unsigned int	nbr;
	char			*str;

	nbr = num;
	len = signcounter(num);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
