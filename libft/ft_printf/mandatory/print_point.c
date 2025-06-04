/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:16:22 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 00:50:08 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	zero_conv(long nbr, t_format *f, int len)
{
	int	c;
	int	i;

	i = 0;
	if (f->width > f->prec)
		c = f->width - f ->prec - len;
	else
	{
		if (nbr < 0)
			len--;
		c = f->prec - len;
	}
	f -> type = 0;
	while (i < c)
		i += write(1, "0", 1);
	return (i);
}

static unsigned long	minus_conv(unsigned long nbr, t_format *f, int base)
{
	int	c;
	int	i;
	int	h;

	i = 0;
	h = 3;
	while (nbr / base != 0)
	{
		h++;
		nbr /= base;
	}
	c = f ->width - h;
	f->width = 0;
	f -> type = 0;
	while (i < c)
		i += write(1, " ", 1);
	return (i);
}
	// if (nbr == -ULONG_MAX)
	// 	c = 11; l32/33

unsigned long	print_h(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	char	*low_base;

	i = 0;
	low_base = "0123456789abcdef";
	if (nbr < base)
		i += ft_putchar(low_base[nbr]);
	else
	{
		i += print_h(nbr / base, base, f);
		if (i == -1)
			return (-1);
		i += print_h(nbr % base, base, f);
	}
	return (i);
}

	// if (nbr == (unsigned long) NULL)
	// 	return (i += write(1, "(nil)", 5), i);
unsigned long	print_point(unsigned long nbr, unsigned int base, t_format *f)
{
	int		i;
	int		len;

	i = 0;
	len = ft_digit_len(nbr, base, f);
	if (f->width > i && f->minus == 0 && f->zero == 0)
		i += (minus_conv(nbr, f, base));
	i += ft_putchar('0');
	i += ft_putchar('x');
	if (f ->width > len && f->minus == 0 && f->zero == 1)
		i += zero_conv(nbr, f, len);
	i += print_h(nbr, base, f);
	if (f->width > i && f->minus == 1)
		i += (minus_conv(nbr, f, base));
	return (i);
}
