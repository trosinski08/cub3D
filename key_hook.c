/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:51:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/21 23:02:07 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_keyhook(mlx_key_data_t keydata, void *param);
void	look_right(t_game *game);
void	look_left(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	fill_with_color(mlx_image_t *img, u_int32_t color);

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	if (keydata.key == 87 && (keydata.action == 1 || keydata.action == 2))
		move_forward(game);
	if (keydata.key == 83 && (keydata.action == 1 || keydata.action == 2))
		move_backward(game);
	if (keydata.key == 65 && (keydata.action == 1 || keydata.action == 2))
		game->player.pos_x -= 5;
	if (keydata.key == 68 && (keydata.action == 1 || keydata.action == 2))
		game->player.pos_x += 5;
	if (keydata.key == 262 && (keydata.action == 1 || keydata.action == 2))
		look_right(game);
	if (keydata.key == 263 && (keydata.action == 1 || keydata.action == 2))
		look_left(game);
	if ((keydata.action == 1 || keydata.action == 2) \
	&& (keydata.key == 65 || keydata.key == 68))
		game->draw_start = 1;
	if (keydata.key == 256 && keydata.action == 1)
		exit(0);
	if (keydata.key == 257 && keydata.action == 1 && game->enter_flag == 0)
	{
		game->enter_flag = 1;
		mlx_delete_image(game->mlx, game->img);
		game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
		fill_with_color(game->img, get_rgba(0, 0, 0, 255));
		mlx_image_to_window(game->mlx, game->img, 0, 0);
		mlx_loop_hook(game->mlx, new_image, game);
	}
}



void	look_right(t_game *game)
{
	game->player.dir += 0.1;
	if (game->player.dir > 2 * PI)
		game->player.dir -= 2 * PI;
	game->player.p_delta_x = cos(game->player.dir) * 5;
	game->player.p_delta_y = sin(game->player.dir) * 5;
	game->draw_start = 1;
}

void	look_left(t_game *game)
{
	game->player.dir -= 0.1;
	if (game->player.dir < 0)
		game->player.dir += 2 * PI;
	game->player.p_delta_x = cos(game->player.dir) * 5;
	game->player.p_delta_y = sin(game->player.dir) * 5;
	game->draw_start = 1;
}


void	move_forward(t_game *game)
{
	game->player.pos_y -= 5;
	game->draw_start = 1;
}

void	move_backward(t_game *game)
{
	game->player.pos_y += 5;
	game->draw_start = 1;
}
