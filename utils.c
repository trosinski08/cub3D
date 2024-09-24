/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:04:31 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/23 22:42:56 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

u_int32_t	get_rgba(int r, int g, int b, int a);
void		fill_with_color(mlx_image_t *img, \
			u_int32_t color, u_int32_t color2);
double		fix_ang(double a);

u_int32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fill_with_color(mlx_image_t *img, u_int32_t color, u_int32_t color2)
{
	u_int32_t	x;
	u_int32_t	y;

	x = -1;
	while (++x < img->width)
	{
		y = -1;
		while (++y < img->height / 2)
			mlx_put_pixel(img, x, y, color);
		while (++y < img->height)
			mlx_put_pixel(img, x, y, color2);
	}
}

double	fix_ang(double a)
{
	if (a > 2 * PI)
		a -= 2 * PI;
	if (a < 0)
		a += 2 * PI;
	return (a);
}
