/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:25:45 by trosinsk          #+#    #+#             */
/*   Updated: 2024/06/24 02:26:09 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	p1;
	int	p2;
	int	p3;
	int	p4;

	ft_printf("\n-----------------TEST-----------------\n");
	p1 = ft_printf("%-5.X, %-5.x, %-5.X, %-5.X, %-5.X, %-5.X, \
	%-5.X, %-5.X", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	ft_printf("\nbytes\t:%d\n", p1);
	ft_printf("\n-----------------TEST-----------------\n");
	p2 = printf("%-5.X, %-5.x, %-5.X, %-5.X, %-5.X, %-5.X, \
	%-5.X, %-5.X", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("\nbytes\t:%d\n", p2);
	ft_printf("\n-----------------TEST-----------------\n");
	p3 = ft_printf("%-5.x, %-5.x, %-5.x, %-5.x, %-5.x, %-5.x, \
	%-5.x, %-5.x", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	ft_printf("\nbytes\t:%d\n", p3);
	ft_printf("\n-----------------TEST-----------------\n");
	p4 = printf("%-5.x, %-5.x, %-5.x, %-5.x, %-5.x, %-5.x, \
	%-5.x, %-5.x", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("\nbytes\t:%d\n", p4);
	ft_printf("\n-----------------TEST-----------------\n");
	if (p1 != p2 || p3 != p4)
	{
		ft_printf("Error: Output mismatch between ft_printf and printf.\n");
		return (1);
	}
	return (0);
}
