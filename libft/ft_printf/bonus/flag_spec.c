/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 02:33:42 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 02:33:42 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	flag_spec(char fspec, t_format *flags)
{
	if (fspec == '-')
		flags->minus = 1;
	else if (fspec == '+')
		flags->plus = 1;
	else if (fspec == ' ')
		flags->space = 1;
	else if (fspec == '0')
		flags->zero = 1;
	else if (fspec == '#')
		flags->hash = 1;
	else if (fspec == '.')
		flags->dot = 1;
	else if (fspec >= '1' && fspec <= '9')
	{
		if (flags->dot == 1)
			flags->prec = flags->prec * 10 + (fspec - '0');
		else
			flags->width = flags->width * 10 + (fspec - '0');
	}
}
