/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:25:32 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/09 18:52:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Converts a string representation of an integer to an integer value.
 *
 * @param num The string representation of the integer.
 * @return The converted integer value.
 */
int	ft_atoi(const char *num)
{
	int	i;
	int	sign;
	int	conv_value;

	i = 0;
	sign = 1;
	conv_value = 0;
	while ((num[i] >= 9 && num[i] <= 13) || num[i] == 32)
		i++;
	if (num[i] == '\0')
		return (0);
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sign = -sign;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		conv_value = (num[i] - '0') + (conv_value * 10);
		i++;
	}
	return (conv_value * sign);
}
