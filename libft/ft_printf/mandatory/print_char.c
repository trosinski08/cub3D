/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:56:48 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/12 21:47:38 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(int c, t_format *f)
{
	int	i;
	int	d;

	i = 0;
	d = f ->width;
	if (c == '%')
		c = '%';
	if (d > 1 && f ->minus == 1)
	{
		i += write(1, &c, 1);
		while (i < d)
			i += write(1, " ", 1);
	}
	else if (d > 0 && f ->minus == 0)
	{
		while (i < d - 1)
			i += write(1, " ", 1);
		i += write(1, &c, 1);
	}
	else
		i += write(1, &c, 1);
	f ->width = 0;
	f ->type = 0;
	return (i);
}
	// int	i;
	// int	d;

	// i = 0;
	// d = f ->width;
	// if (d > 1 && f ->minus == 1)
	// {
	// 	i += write(1, &c, 1);
	// 	while (i < d)
	// 		i += write(1, " ", 1);
	// }
	// else if (d > 0 && f ->minus == 0)
	// {
	// 	while (i < d - 1)
	// 		i += write(1, " ", 1);
	// 	i += write(1, &c, 1);
	// }
	// else
	// 	i += write(1, &c, 1);
	// f ->width = 0;
	// f ->type = 0;
	// return (i);