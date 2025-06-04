/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:00:00 by trosinsk          #+#    #+#             */
/*   Updated: 2024/05/24 12:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#define NBR_BUFFER_SIZE 32

static void	reverse_str(char *str, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int	ft_itoa_base(char *buffer, unsigned long long n, int base, int uppercase)
{
	int		i;
	char	digit;
	char	*digits_set;

	if (uppercase)
		digits_set = "0123456789ABCDEF";
	else
		digits_set = "0123456789abcdef";
	i = 0;
	if (n == 0)
		buffer[i++] = '0';
	while (n)
	{
		digit = digits_set[n % base];
		buffer[i++] = digit;
		n /= base;
	}
	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (i);
}
