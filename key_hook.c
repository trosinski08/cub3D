/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:51:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 16:15:39 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param);
void	left_right_look(t_game *game, double step, mlx_key_data_t keydata);
void	movements(t_game *game, mlx_key_data_t keydata, double step);
void	left_right_movements(t_game *game, mlx_key_data_t keydata, double step);
void	backward_movements(t_game *game, mlx_key_data_t keydata);

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	double	step;

	game = (t_game *)param;
	step = TILE_SZ / 8;
	game->player.p_delta_x = cos(game->player.dir) * step;
	game->player.p_delta_y = -sin(game->player.dir) * step;
	if (keydata.action == 2)
		step = (TILE_SZ / 4) * 3;
	game->player.dir = fix_ang(game->player.dir);
	movements(game, keydata, step);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT) \
	&& (keydata.action == 1 || keydata.action == 2))
		left_right_look(game, step, keydata);
	if (keydata.key == 256 && keydata.action == 1)
		exit(0);
	if (keydata.key == 257 && keydata.action == 1 && game->enter_flag == 0)
	{
		game->enter_flag = 1;
		game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
		mlx_loop_hook(game->mlx, new_game, game);
		mlx_image_to_window(game->mlx, game->img, 0, 0);
		game->draw_start = 1;
	}
}

void	left_right_look(t_game *game, double step, mlx_key_data_t keydata)
{
	game->player.dir = fix_ang(game->player.dir);
	if (keydata.key == MLX_KEY_LEFT)
	{
		game->player.dir += 0.1;
		if (game->player.dir > 2 * PI)
			game->player.dir -= 2 * PI;
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		game->player.dir -= 0.1;
		if (game->player.dir < 0)
			game->player.dir += 2 * PI;
	}
	game->player.p_delta_x = cos(game->player.dir) * step;
	game->player.p_delta_y = -sin(game->player.dir) * step;
	game->draw_start = 1;
}

void	movements(t_game *game, mlx_key_data_t keydata, double step)
{
	if (keydata.key == 87 && (keydata.action == 1 || keydata.action == 2))
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
	if (keydata.key == 83 && (keydata.action == 1 || keydata.action == 2))
		backward_movements(game, keydata);
	if ((keydata.key == 65 || keydata.key == 68) && (keydata.action == 1 \
	|| keydata.action == 2))
		left_right_movements(game, keydata, step);
}

void	left_right_movements(t_game *game, mlx_key_data_t keydata, double step)
{
	if (keydata.key == 65 && (keydata.action == 1 || keydata.action == 2))
	{
		game->player.pos_x += sin(-game->player.dir) * step / 2;
		game->player.pos_y -= cos(-game->player.dir) * step / 2;
		while (game->map.map[(int)game->player.pos_y / TILE_SZ] \
		[(int)game->player.pos_x / TILE_SZ] == 1)
		{
			step *= 0.5;
			game->player.pos_x -= sin(game->player.dir) * step / 2;
			game->player.pos_y += cos(game->player.dir) * step / 2;
		}
	}
	if (keydata.key == 68 && (keydata.action == 1 || keydata.action == 2))
	{
		game->player.pos_x += sin(game->player.dir) * step / 2;
		game->player.pos_y += cos(game->player.dir) * step / 2;
		while (game->map.map[(int)game->player.pos_y / TILE_SZ] \
		[(int)game->player.pos_x / TILE_SZ] == 1)
		{
			step *= 0.5;
			game->player.pos_x -= (sin(game->player.dir) * step / 2);
			game->player.pos_y -= cos(game->player.dir) * step / 2;
		}
	}
	game->draw_start = 1;
}

void	backward_movements(t_game *game, mlx_key_data_t keydata)
{
	if (keydata.key == 83 && (keydata.action == 1 || keydata.action == 2))
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
}
