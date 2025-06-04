/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:32:30 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 00:19:17 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	flag_spec(char fspec, t_format *flags)
{
	if (fspec == '0' && !flags->type && !flags->minus && !flags->dot)
		flags->zero = 1;
	else if (ft_strchr("0123456789", fspec))
	{
		flags->type = flags->type * 10 + (fspec - '0');
		if (flags->dot == 0)
			flags->width = flags->type;
		else
			flags->prec = flags->type;
	}
	if (fspec == '-')
		flags->minus = 1;
	else if (fspec == '.')
	{
		flags->dot = 1;
		flags->type = 0;
	}
	else if (fspec == '+')
		flags->plus = 1;
	else if (fspec == ' ')
		flags->space = 1;
	else if (fspec == '#')
		flags->hash = 1;
}
