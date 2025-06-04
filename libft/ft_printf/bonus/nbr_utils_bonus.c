/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:33:42 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 02:33:42 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	determine_padding_char(t_format *f)
{
	if (f->zero && !f->minus && (!f->dot || f->type == '%'))
		return ('0');
	return (' ');
}

int	get_precision_zeros_len(long nbr, t_format *f, int len)
{
	int	precision_zeros;

	precision_zeros = 0;
	if (f->dot && f->prec > len - (nbr < 0 || f->plus || f->space))
		precision_zeros = f->prec - len + (nbr < 0 || f->plus || f->space);
	return (precision_zeros);
}

int	get_width_padding_len(t_format *f, int len, int precision_zeros)
{
	int	width_padding;

	width_padding = 0;
	if (f->width > len + precision_zeros)
		width_padding = f->width - len - precision_zeros;
	return (width_padding);
}

static int	handle_padding_flags(long nbr, t_format *f, char pad_char)
{
	int	i;

	i = 0;
	if (nbr < 0)
		i += minus_nbr(f);
	else if (f->plus || f->space)
		i += plus_conv(f);
	if (f->hash && nbr != 0)
		i += print_hash_flag_prefix(nbr, f);
	return (i);
}

int	non_minus_conv(long nbr, t_format *f, int len)
{
	int		i;
	int		precision_zeros;
	int		width_padding;
	char	pad_char;

	i = 0;
	if (nbr == 0 && f->dot && f->prec == 0)
		len = 0;
	precision_zeros = get_precision_zeros_len(nbr, f, len);
	width_padding = get_width_padding_len(f, len, precision_zeros);
	pad_char = determine_padding_char(f);
	if (width_padding > 0)
	{
		if (pad_char == '0')
			i += handle_padding_flags(nbr, f, pad_char);
		i += print_padding_chars(width_padding, pad_char);
	}
	if (pad_char == ' ')
		i += handle_padding_flags(nbr, f, pad_char);
	i += print_padding_chars(precision_zeros, '0');
	return (i);
}
