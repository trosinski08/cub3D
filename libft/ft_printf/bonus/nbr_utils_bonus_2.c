/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:33:42 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 02:33:42 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	handle_zero_padding(long nbr, t_format *f, int *i)
{
	if (nbr < 0)
		*i += minus_nbr(f);
	else if (f->plus || f->space)
		*i += plus_conv(f);
	if (f->hash && nbr != 0)
		*i += print_hash_flag_prefix(nbr, f);
	return (*i);
}

int	apply_width_padding_and_sign(long nbr, t_format *f, \
int width_pad_len_char_pad)
{
	char	pad_char;
	int		i;

	i = 0;
	if (!f->minus && width_pad_len_char_pad > 0)
	{
		pad_char = determine_padding_char(f);
		if (pad_char == '0')
			i = handle_zero_padding(nbr, f, &i);
		i += print_padding_chars(width_pad_len_char_pad, pad_char);
	}
	return (i);
}

int	print_hash_flag_prefix(long nbr, t_format *f)
{
	int	i;

	i = 0;
	if (nbr != 0 && f->hash)
	{
		i += write(1, "0", 1);
		if (f->type == 'x')
			i += write(1, "x", 1);
		else if (f->type == 'X')
			i += write(1, "X", 1);
	}
	return (i);
}

int	print_padding_chars(int count, char pad_char_val)
{
	int	i;

	i = 0;
	while (i < count)
		i += write(1, &pad_char_val, 1);
	return (i);
}
