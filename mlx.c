/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:58:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/21 00:08:27 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		new_tile_size(t_game *game);
void	new_image(void *param);

int	new_tile_size(t_game *game)
{
	int		xo;
	int		yo;

	xo = WIDTH / game->map.width;
	yo = HEIGHT / game->map.height;
	if (xo > yo)
		xo = yo;
	else
		yo = xo;
	return (xo);
}

void	new_image(void *param)
{
	t_game		*game;
	u_int32_t	color;
	int			x;
	int			y;
	int			xo;

	game = (t_game *)param;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	xo = new_tile_size(game);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			color = get_rgba(0, 0, 0, 255);
			if ((y / xo < game->map.height) && game->map.map[y / xo][x / xo] && \
		game->map.map[y / xo][x / xo] == WALL && (x % xo != 0 && y % xo != 0))
				color = get_rgba(255, 255, 255, 255);
			if ((x % xo == 0 || y % xo == 0) && game->map.map[y / xo][x / xo] \
		!= WALL && (x <= xo * game->map.width && y <= xo * game->map.height))
				color = get_rgba(255, 255, 255, 255);
			mlx_put_pixel(game->img, x, y, color);
		}
	}
	draw_player(game, xo);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
