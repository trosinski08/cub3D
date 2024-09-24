/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:23:53 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/22 21:44:36 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	greater_than_zero(t_game *game, double tang);
static void	smaller_than_zero(t_game *game, double tang);
void		check_horizontal_hit(t_game *game);
void		horizontal_dist(t_game *game, int i);

void	check_horizontal_hit(t_game *game)
{
	double	rev_tan;
	int		i;

	i = 0;
	game->ray.h_dist = 1000000000000;
	rev_tan = 1.0 / tan(game->ray.dir);
	if (sin(game->ray.dir) > 0.001)
		greater_than_zero(game, rev_tan);
	else if (sin(game->ray.dir) < -0.001)
		smaller_than_zero(game, rev_tan);
	else
	{
		game->ray.x = game->player.pos_x;
		game->ray.y = game->player.pos_y;
		i = game->map.height;
	}
	while (i < game->map.height)
		horizontal_dist(game, i++);
}

static void	greater_than_zero(t_game *game, double rev_tan)
{
	game->ray.y = (int)game->player.pos_y / TILE_SZ * TILE_SZ - 0.0001;
	game->ray.x = (game->player.pos_y - game->ray.y) \
	* rev_tan + game->player.pos_x;
	game->player.temp_y = -TILE_SZ;
	game->player.temp_x = -game->player.temp_y * rev_tan;
}

static void	smaller_than_zero(t_game *game, double rev_tan)
{
	game->ray.y = (int)game->player.pos_y / TILE_SZ * TILE_SZ + TILE_SZ;
	game->ray.x = (game->player.pos_y - game->ray.y) \
	* rev_tan + game->player.pos_x;
	game->player.temp_y = TILE_SZ;
	game->player.temp_x = -game->player.temp_y * rev_tan;
}

void	horizontal_dist(t_game *game, int i)
{
	game->ray.hit_x = game->ray.x / TILE_SZ;
	game->ray.hit_y = game->ray.y / TILE_SZ;
	if (game->ray.hit_x >= 0 && game->ray.hit_y >= 0 && game->ray.hit_x <= \
	game->map.width && game->ray.hit_y <= game->map.height && game->map.map \
	[(int)game->ray.hit_y][(int)game->ray.hit_x] == 1)
	{
		game->ray.temp_hx = game->ray.x;
		game->ray.temp_hy = game->ray.y;
		game->ray.h_dist = cos(game->ray.dir) * (game->ray.x - game->player.\
		pos_x) - sin(game->ray.dir) * (game->ray.y - game->player.pos_y);
		i = 8;
	}
	else
	{
		game->ray.x += game->player.temp_x;
		game->ray.y += game->player.temp_y;
	}
}
