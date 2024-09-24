/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:24:17 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/22 21:45:05 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	greater_than_zero(t_game *game, double tang);
static void	smaller_than_zero(t_game *game, double tang);
void		check_vertical_hit(t_game *game);
void		vertical_dist(t_game *game, int i);

void	check_vertical_hit(t_game *game)
{
	double	tang;
	int		i;

	i = 0;
	game->ray.v_dist = 100000000000;
	tang = tan(game->ray.dir);
	if (cos(game->ray.dir) < -0.001)
		smaller_than_zero(game, tang);
	else if (cos(game->ray.dir) > 0.001)
		greater_than_zero(game, tang);
	else
	{
		game->ray.x = game->player.pos_x;
		game->ray.y = game->player.pos_y;
		i = game->map.width;
	}
	while (i < game->map.width)
		vertical_dist(game, i++);
}

void	smaller_than_zero(t_game *game, double tang)
{
	game->ray.x = (int)game->player.pos_x / TILE_SZ * TILE_SZ - 0.0001;
	game->ray.y = (game->player.pos_x - game->ray.x) * tang + \
	game->player.pos_y;
	game->player.temp_x = -TILE_SZ;
	game->player.temp_y = -game->player.temp_x * tang;
}

void	greater_than_zero(t_game *game, double tang)
{
	game->ray.x = (int)game->player.pos_x / TILE_SZ * TILE_SZ + TILE_SZ;
	game->ray.y = (game->player.pos_x - game->ray.x) * tang + \
	game->player.pos_y;
	game->player.temp_x = TILE_SZ;
	game->player.temp_y = -game->player.temp_x * tang;
}

void	vertical_dist(t_game *game, int i)
{
	game->ray.hit_x = game->ray.x / TILE_SZ;
	game->ray.hit_y = game->ray.y / TILE_SZ;
	if (game->ray.hit_x >= 0 && game->ray.hit_y >= 0 && game->ray.hit_x <= \
	game->map.width && game->ray.hit_y <= game->map.height && game->map.map \
	[(int)game->ray.hit_y][(int)game->ray.hit_x] != 0)
	{
		game->ray.temp_vx = game->ray.x;
		game->ray.temp_vy = game->ray.y;
		game->ray.v_dist = cos(game->ray.dir) * (game->ray.x - game->player.\
		pos_x) - sin(game->ray.dir) * (game->ray.y - game->player.pos_y);
		i = 8;
	}
	else
	{
		game->ray.x += game->player.temp_x;
		game->ray.y += game->player.temp_y;
	}
}
