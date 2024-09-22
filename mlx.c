/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:58:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/22 03:58:20 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_image(void *param);

void	new_image(void *param)
{
	t_game		*game;
	u_int32_t	color;
	int			x;
	int			y;

	game = (t_game *)param;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	x = -1;
	while (++x < game->map.width * TILE_SZ)
	{
		y = -1;
		while (++y < game->map.height * TILE_SZ)
		{
			color = game->map.floor;
			// if (y % TILE_SZ == 0 || x % TILE_SZ == 0)
			// 	color = get_rgba(0, 255, 126, 126);
			// else 
			if (game->map.map[y / TILE_SZ][x / TILE_SZ] && \
			game->map.map[y / TILE_SZ][x / TILE_SZ] == WALL)
				color = game->map.ceiling;
			mlx_put_pixel(game->img, x, y, color);
		}
	}
	draw_player(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
