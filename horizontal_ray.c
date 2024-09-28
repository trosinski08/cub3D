/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:23:53 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 14:37:08 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_h_step(t_game *game, double rev_tan, int direction);
void		check_horizontal_hit(t_game *game);
void		horizontal_dist(t_game *game, int i);

void	check_horizontal_hit(t_game *game)
{
	double	rev_tan;
	int		i;

	i = 0;
	game->ray.h_dist = INT_MAX;
	rev_tan = 1.0 / tan(game->ray.dir);
	if (game->ray.dir > 0 && game->ray.dir < PI)
		calc_h_step(game, rev_tan, -1);
	else if (game->ray.dir > PI && game->ray.dir < 2 * PI)
		calc_h_step(game, rev_tan, 1);
	else
	{
		game->ray.x = game->player.pos_x;
		game->ray.y = game->player.pos_y;
		i = game->map.height;
	}
	while (i < game->map.height)
		horizontal_dist(game, i++);
}

static	void	calc_h_step(t_game *game, double rev_tan, int direction)
{
	game->ray.y = (int)game->player.pos_y / TILE_SZ * TILE_SZ;
	if (direction == 1)
		game->ray.y += TILE_SZ;
	else
		game->ray.y -= 0.0001;
	game->ray.x = game->player.pos_x + \
	(game->player.pos_y - game->ray.y) * rev_tan;
	game->player.temp_y = direction * TILE_SZ;
	game->player.temp_x = -game->player.temp_y * rev_tan;
}

void	horizontal_dist(t_game *game, int i)
{
	double	dx;
	double	dy;

	game->ray.hit_x = game->ray.x / TILE_SZ;
	game->ray.hit_y = game->ray.y / TILE_SZ;
	if (game->ray.hit_x >= 0 && game->ray.hit_y >= 0 && game->ray.hit_x <= \
	game->map.width && game->ray.hit_y <= game->map.height && game->map.map \
	[(int)game->ray.hit_y][(int)game->ray.hit_x] == 1)
	{
		dx = game->ray.x - game->player.pos_x;
		dy = game->ray.y - game->player.pos_y;
		game->ray.temp_hx = game->ray.x;
		game->ray.temp_hy = game->ray.y;
		game->ray.h_dist = sqrt(dx * dx + dy * dy);
		i = game->map.height;
	}
	else
	{
		game->ray.x += game->player.temp_x;
		game->ray.y += game->player.temp_y;
	}
}
