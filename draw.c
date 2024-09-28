/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:58:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 21:09:10 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// u_int32_t	check_hit(t_game *game);
void		new_game(void *param);
void		draw_mini_map(t_game *game);
void		draw_player(t_game *game);
void		draw_ray(t_game *game);
void		draw_line(t_game *game, int x2, int y2);

void	new_game(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	game->draw_start = 1;
	raytrace(game);
	draw_mini_map(game);
	draw_player(game);
	draw_ray(game);
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
				color = get_rgba(0, 0, 0, 255);
			else if (game->map.map[y / TILE_SZ][x / TILE_SZ] && \
			game->map.map[y / TILE_SZ][x / TILE_SZ] == WALL)
				color = get_rgba(255, 255, 255, 255);
			mlx_put_pixel(game->img, x, y, color);
		}
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;
	int	half_size;

	half_size = 2;
	x = game->player.pos_x - half_size;
	while (x <= game->player.pos_x + half_size)
	{
		y = game->player.pos_y - half_size;
		while (y <= game->player.pos_y + half_size)
		{
			mlx_put_pixel(game->img, x, y, get_rgba(255, 255, 0, 255));
			y++;
		}
		x++;
	}
}

void	draw_ray(t_game *game)
{
	int		ray_x;
	int		ray_y;
	double	angle;
	int		distance;

	angle = game->player.dir + game->player.fov / 2;
	while (angle > game->player.dir - game->player.fov / 2)
	{
		distance = 0;
		while (distance < TILE_SZ * game->map.width)
		{
			ray_x = game->player.pos_x + cos(angle) * distance;
			ray_y = game->player.pos_y - sin(angle) * distance;
			if (ray_x < game->map.width * TILE_SZ && ray_y < game->map.height \
			* TILE_SZ && ray_x > 0 && ray_y > 0 && game->map.map[(int)ray_y / \
			TILE_SZ][(int)ray_x / TILE_SZ] == 0)
				draw_line(game, ray_x, ray_y);
			distance += TILE_SZ / 4;
		}
		angle -= 0.01;
	}
}

void	draw_line(t_game *game, int x2, int y2)
{
	double	dx;
	double	dy;
	double	step;
	double	x;
	double	y;

	dx = x2 - game->player.pos_x;
	dy = y2 - game->player.pos_y;
	step = fmax(fabs(dx), fabs(dy));
	dx /= step;
	dy /= step;
	x = game->player.pos_x;
	y = game->player.pos_y;
	while ((int)(x - x2) || (int)(y - y2))
	{
		if (x < game->map.width * TILE_SZ && y < game->map.height * TILE_SZ \
	&& x > 0 && y > 0 && game->map.map[(int)y / TILE_SZ][(int)x / TILE_SZ] == 0)
			mlx_put_pixel(game->img, x, y, WALL_COLOR);
		else
			break ;
		x += dx;
		y += dy;
	}
}
