/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:30 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 02:18:40 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	minus_nbr(t_format *f)
{
	int	i;

	i = 0;
	i += write (1, "-", 1);
	if (i == -1)
		return (-1);
	f -> plus = 0;
	f -> space = 0;
	return (i);
}

int	plus_conv(t_format *f)
{
	int	i;

	i = 0;
	i += write(1, "+", 1);
	if (i == -1)
		return (-1);
	f->plus = 0;
	f->space = 0;
	return (i);
}

int	space_conv(t_format *f)
{
	int	i;

	i = 0;
	i += write(1, " ", 1);
	if (i == -1)
		return (-1);
	f->plus = 0;
	f->space = 0;
	return (i);
}

int	print_digit(long nbr, int base)
{
	int		i;
	char	*low_base;

	i = 0;
	low_base = "0123456789abcdef";
	if (nbr < 0)
		nbr *= -1;
	if (nbr < base)
		i += ft_putchar(low_base[nbr]);
	else
	{
		i += print_digit(nbr / base, base);
		if (i == -1)
			return (-1);
		i += print_digit(nbr % base, base);
	}
	return (i);
}

int	ft_digit_len(long nbr, int base, t_format *f)
{
	int		i;
	long	temp;

	i = 1;
	temp = nbr;
	if ((f->plus == 1 || f->space == 1) && nbr >= 0)
		i++;
	if (temp < 0)
	{
		temp *= -1;
		i++;
	}
	while (temp / base != 0)
	{
		i++;
		temp /= base;
	}
	return (i);
}
