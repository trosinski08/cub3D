/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:51:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/24 02:03:22 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param);
void	look_right(t_game *game, double step);
void	look_left(t_game *game, double step);
void	movements(t_game *game, mlx_key_data_t keydata);
void	push_enter(t_game *game);

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	double	step;

	game = (t_game *)param;
	step = TILE_SZ / 2;
	if (keydata.action == 2)
		step = (TILE_SZ / 4) * 3;
	movements(game, keydata);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == 1 || \
	keydata.action == 2))
		look_right(game, step);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == 1 || \
	keydata.action == 2))
		look_left(game, step);
	if ((keydata.action == 1 || keydata.action == 2) \
	&& (keydata.key == 65 || keydata.key == 68))
		game->draw_start = 1;
	if (keydata.key == 256 && keydata.action == 1)
		exit(0);
	if (keydata.key == 257 && keydata.action == 1 && game->enter_flag == 0)
		push_enter(game);
}

void	push_enter(t_game *game)
{
	game->enter_flag = 1;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_loop_hook(game->mlx, new_image, game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	game->draw_start = 1;
}

void	look_left(t_game *game, double step)
{
	game->player.dir = fix_ang(game->player.dir);
	game->player.dir += 0.1;
	if (game->player.dir > 2 * PI)
		game->player.dir -= 2 * PI;
	game->player.p_delta_x = cos(game->player.dir) * step;
	game->player.p_delta_y = -sin(game->player.dir) * step;
	game->draw_start = 1;
}

void	look_right(t_game *game, double step)
{
	game->player.dir = fix_ang(game->player.dir);
	game->player.dir -= 0.1;
	if (game->player.dir < 0)
		game->player.dir += 2 * PI;
	game->player.p_delta_x = cos(game->player.dir) * step;
	game->player.p_delta_y = -sin(game->player.dir) * step;
	game->draw_start = 1;
}

void	movements(t_game *game, mlx_key_data_t keydata)
{
	double	step;

	step = TILE_SZ / 4;
	if (keydata.key == MLX_KEY_W && (keydata.action == 1 \
	|| keydata.action == 2))
	{
		game->player.pos_x += game->player.p_delta_x;
		game->player.pos_y += game->player.p_delta_y;
		while (game->map.map[(int)game->player.pos_y / TILE_SZ] \
		[(int)game->player.pos_x / TILE_SZ] == 1)
		{
			game->player.pos_x -= game->player.p_delta_x;
			game->player.pos_y -= game->player.p_delta_y;
		}
		game->draw_start = 1;
	}
	if (keydata.key == MLX_KEY_S && (keydata.action == 1 \
	|| keydata.action == 2))
	{
		game->player.pos_x -= game->player.p_delta_x;
		game->player.pos_y -= game->player.p_delta_y;
		while (game->map.map[(int)game->player.pos_y / TILE_SZ] \
		[(int)game->player.pos_x / TILE_SZ] == 1)
		{
			game->player.pos_x += game->player.p_delta_x;
			game->player.pos_y += game->player.p_delta_y;
		}
		game->draw_start = 1;
	}
	if (keydata.key == MLX_KEY_A && (keydata.action == 1 \
	|| keydata.action == 2))
	{
		game->player.pos_x += sin(-game->player.dir) * step;
		game->player.pos_y -= cos(-game->player.dir) * step;
		while (game->map.map[(int)game->player.pos_y / TILE_SZ] \
		[(int)game->player.pos_x / TILE_SZ] == 1)
		{
			step *= 0.5;
			game->player.pos_x -= sin(game->player.dir) * step;
			game->player.pos_y += cos(game->player.dir) * step;
		}
		game->draw_start = 1;
	}
	if (keydata.key == MLX_KEY_D && (keydata.action == 1 \
	|| keydata.action == 2))
	{
		game->player.pos_x += sin(game->player.dir) * step;
		game->player.pos_y += cos(game->player.dir) * step;
		while (game->map.map[(int)game->player.pos_y / TILE_SZ] \
		[(int)game->player.pos_x / TILE_SZ] == 1)
		{
			step *= 0.5;
			game->player.pos_x -= (sin(game->player.dir) * step);
			game->player.pos_y -= cos(game->player.dir) * step;
		}
		game->draw_start = 1;
	}
}
