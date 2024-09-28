/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:24:17 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 20:12:25 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_v_step(t_game *game, double tang, int direction);
void		check_vertical_hit(t_game *game);
void		vertical_dist(t_game *game, int i);

void	check_vertical_hit(t_game *game)
{
	double	tang;
	int		i;

	i = 0;
	game->ray.v_dist = INT_MAX;
	tang = tan(game->ray.dir);
	if (game->ray.dir > PI / 2 && game->ray.dir < 3 * PI / 2)
		calc_v_step(game, tang, -1);
	else if (game->ray.dir < PI / 2 || game->ray.dir > 3 * PI / 2)
		calc_v_step(game, tang, 1);
	else
	{
		game->ray.x = game->player.pos_x;
		game->ray.y = game->player.pos_y;
		i = game->map.width;
	}
	while (i < game->map.width)
	{
		vertical_dist(game, i);
		i++;
	}
}

static	void	calc_v_step(t_game *game, double tang, int direction)
{
	game->ray.x = (int)game->player.pos_x / TILE_SZ * TILE_SZ;
	if (direction == 1)
		game->ray.x += TILE_SZ;
	else
		game->ray.x -= 0.0001;
	game->ray.y = game->player.pos_y + \
	(game->player.pos_x - game->ray.x) * tang;
	game->player.temp_x = direction * TILE_SZ;
	game->player.temp_y = -game->player.temp_x * tang;
}

void	vertical_dist(t_game *game, int i)
{
	double	dx;
	double	dy;

	game->ray.hit_x = game->ray.x / TILE_SZ;
	game->ray.hit_y = game->ray.y / TILE_SZ;
	if (game->ray.hit_x >= 0 && game->ray.hit_y >= 0 && game->ray.hit_x <= \
	game->map.width && game->ray.hit_y <= game->map.height && game->map.map \
	[(int)game->ray.hit_y][(int)game->ray.hit_x] == 1)
	{
		game->ray.temp_vx = game->ray.x;
		game->ray.temp_vy = game->ray.y;
		dx = game->ray.x - game->player.pos_x;
		dy = game->ray.y - game->player.pos_y;
		game->ray.v_dist = sqrt(dx * dx + dy * dy);
		i = game->map.width;
	}
	else
	{
		game->ray.x += game->player.temp_x;
		game->ray.y += game->player.temp_y;
	}
}
