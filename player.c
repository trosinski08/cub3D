/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:14:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/21 00:55:55 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_game *game, int xo);
void	draw_ray(t_game *game, int xo);
void	lin_interp(t_game *game, double x2, double y2);

void	draw_player(t_game *game, int xo)
{
	u_int32_t	color;
	int			x;
	int			y;

	color = get_rgba(255, 255, 0, 255);
	x = game->player.pos_x - 5;
	while (x < game->player.pos_x + 5)
	{
		y = game->player.pos_y - 5;
		while (y < game->player.pos_y + 5)
		{
			mlx_put_pixel(game->img, x, y, color);
			y++;
		}
		x++;
	}
	draw_ray(game, xo);
}

void	draw_ray(t_game *game, int xo)
{
	int		i;
	double	ray_angle;
	double	ray_x;
	double	ray_y;
	double	ray_dist;

	i = 0;
	ray_angle = game->player.dir - game->player.fov / 2;
	while (ray_angle < game->player.dir + game->player.fov / 2)
	{
		ray_x = game->player.pos_x + cos(ray_angle) * 100;
		ray_y = game->player.pos_y + sin(ray_angle) * 100;
		ray_dist = 0;
		while (game->map.map[(int)ray_y / xo][(int)ray_x / xo] != WALL)
		{
			ray_x += cos(ray_angle) * 5;
			ray_y += sin(ray_angle) * 5;
			ray_dist += 5;
		}
		lin_interp(game, ray_x, ray_y);
		// ray_angle += game->player.fov / WIDTH / 10;
		// printf("Player fov: %f, WIDTH: %d\n", game->player.fov, WIDTH);
		ray_angle += 0.01;
		printf("ray_angle: %f\n", ray_angle);
		i++;
	}
}

void	lin_interp(t_game *game, double x2, double y2)
{
	double	dx;
	double	dy;
	double	step;
	double	x;
	double	y;

	dx = x2 - game->player.pos_x;
	dy = y2 - game->player.pos_y;
	step = fabs(dx);
	if (fabs(dy) > step)
		step = fabs(dy);
	dx /= step;
	dy /= step;
	x = game->player.pos_x;
	y = game->player.pos_y;
	while ((int)(x - x2) || (int)(y - y2))
	{
		mlx_put_pixel(game->img, x, y, get_rgba(255, 0, 0, 255));
		x += dx;
		y += dy;
	}
}
