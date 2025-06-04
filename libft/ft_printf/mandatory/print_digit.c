/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 02:00:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/05/29 01:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	print_pad_chars(int count, char c, int *total)
{
	while (count-- > 0)
		*total += write(1, &c, 1);
}

static int	handle_width_padding(t_format *f, int len)
{
	int	padding;
	int	total;

	total = 0;
	padding = f->width - len;
	if (padding > 0)
		print_pad_chars(padding, ' ', &total);
	return (total);
}

static int	handle_sign(long nbr, t_format *f)
{
	if (nbr < 0)
		return (write(1, "-", 1));
	else if (f->plus)
		return (write(1, "+", 1));
	else if (f->space)
		return (write(1, " ", 1));
	return (0);
}

int	print_digit_prep(long nbr, int base, t_format *f)
{
	int	total;
	int	len;

	total = 0;
	len = ft_digit_len(nbr, base, f);
	if (!f->minus)
		total += handle_width_padding(f, len);
	total += handle_sign(nbr, f);
	if (nbr == 0 && f->dot && f->prec == 0)
		return (total);
	total += print_digit(nbr, base);
	if (f->minus)
		total += handle_width_padding(f, len);
	return (total);
}
