/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:58:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/27 20:20:08 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

u_int32_t	check_hit(t_game *game);
void		new_image(void *param);
void		draw_mini_map(t_game *game);

void	new_image(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	game->draw_start = 1;
	draw_mini_map(game);
	draw_ray(game);
	draw_player(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	draw_mini_map(t_game *game)
{
	u_int32_t	color;
	int			x;
	int			y;

	x = -1;
	while (++x < game->map.width * TILE_SZ)
	{
		y = -1;
		while (++y < game->map.height * TILE_SZ)
		{
			color = game->map.floor * 0.5;
			if (y % TILE_SZ == 0 || x % TILE_SZ == 0 || \
			y % TILE_SZ == TILE_SZ - 1 || x % TILE_SZ == TILE_SZ - 1)
			{
				color = get_rgba(0, 0, 0, 255);
				if (game->map.floor == (int)color)
					color = get_rgba(0, 126, 255, 255);
			}
			else if (game->map.map[y / TILE_SZ][x / TILE_SZ] && \
			game->map.map[y / TILE_SZ][x / TILE_SZ] == WALL)
				color = get_rgba(255, 255, 255, 255);
			mlx_put_pixel(game->img, x, y, color);
		}
	}
}

u_int32_t	check_hit(t_game *game)
{
	u_int32_t	color;

	check_horizontal_hit(game);
	check_vertical_hit(game);
	if (game->ray.h_dist < game->ray.v_dist)
	{
		lin_interp(game, game->ray.temp_hx, game->ray.temp_hy);
		game->ray.dist = game->ray.h_dist;
		color = get_rgba(126, 126, 126, 126);
	}
	else
	{
		lin_interp(game, game->ray.temp_vx, game->ray.temp_vy);
		game->ray.dist = game->ray.v_dist;
		color = get_rgba(126, 126, 126, 255);
	}
	game->mini_flag = 0;
	return (color);
}
