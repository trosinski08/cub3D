/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:14:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/22 15:43:36 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_game *game);
void	draw_ray(t_game *game);
void	lin_interp(t_game *game, double x2, double y2);
void	check_horizontal_hit(t_game *game);
void	check_vertical_hit(t_game *game);
void	draw_line(t_game *game, double x, double y);

void	draw_player(t_game *game)
{
	u_int32_t	color;
	int			x;
	int			y;

	color = get_rgba(255, 255, 0, 255);
	x = game->player.pos_x - TILE_SZ / 2;
	while (x < game->player.pos_x + TILE_SZ / 2)
	{
		y = game->player.pos_y - TILE_SZ / 2;
		while (y < game->player.pos_y + TILE_SZ / 2)
		{
			mlx_put_pixel(game->img, x, y, color);
			y++;
		}
		x++;
	}
	draw_ray(game);
}

void	draw_ray(t_game *game)
{
	game->ray.dir = game->player.dir - game->player.fov / 2;
	while (game->ray.dir < game->player.dir + game->player.fov / 2)
	{
		check_horizontal_hit(game);
		check_vertical_hit(game);
		if (game->ray.h_dist < game->ray.v_dist)
			lin_interp(game, game->ray.temp_hx, game->ray.temp_hy);
			// draw_line(game, game->ray.temp_hx, game->ray.temp_hy);}
		else
			lin_interp(game, game->ray.temp_vx, game->ray.temp_vy);
			// draw_line(game, game->ray.temp_vx, game->ray.temp_vy);}
		game->ray.dir += 0.01;
	}
}
// void	check_vertical_hit(t_game *game)
// {
// 	double	x;
// 	double	y;
// 	double	tang;
// 	int		i;

// 	i = 0;
// 	tang = tan(game->ray.dir);
// 	if (game->ray.dir > PI / 2 && game->ray.dir < 3 * PI / 2)
// 	{
// 		game->ray.x = (int)game->player.pos_x / TILE_SZ * TILE_SZ - 0.0001;
// 		game->ray.y = game->player.pos_y + (game->player.pos_x - game->ray.x) \
// 		* tang;
// 		x = -TILE_SZ;
// 		y = -x * tang;
// 	}
// 	if (game->ray.dir < PI / 2 || game->ray.dir > 3 * PI / 2)
// 	{
// 		game->ray.x = (int)game->player.pos_x / TILE_SZ * TILE_SZ + TILE_SZ;
// 		game->ray.y = game->player.pos_y + (game->player.pos_x - game->ray.x) \
// 		* tang;
// 		x = TILE_SZ;
// 		y = -x * tang;
// 	}
// 	if (game->ray.dir == PI / 2 || game->ray.dir == 3 * PI / 2)
// 	{
// 		game->ray.x = game->player.pos_x;
// 		game->ray.y = game->player.pos_y;
// 		i = 8;
// 	}
// 	while (i < 8)
// 	{
// 		game->ray.hit_x = game->ray.x / TILE_SZ;
// 		game->ray.hit_y = game->ray.y / TILE_SZ;
// 		if (game->ray.hit_x >= 0 && game->ray.hit_y >= 0 && game->ray.hit_x <= \
// 		game->map.width && game->ray.hit_y <= game->map.height && game->map.map \
// 		[(int)game->ray.hit_y][(int)game->ray.hit_x] == 1)
// 		{
// 			game->ray.temp_vx = game->ray.x;
// 			game->ray.temp_vy = game->ray.y;
// 			game->ray.v_dist = sqrt(pow(game->player.pos_x - game->ray.x, 2) + \
// 			pow(game->player.pos_y - game->ray.y, 2));
// 			i = 8;
// 		}
// 		else
// 		{
// 			game->ray.x += x;
// 			game->ray.y += y;
// 			i++;
// 		}
// 	}
// }

void	check_horizontal_hit(t_game *game)
{
	double	x;
	double	y;
	double	rev_tan;
	int		i;

	i = 0;
	game->ray.h_dist = 1000000000000;
	rev_tan = 1.0 / tan(game->ray.dir);
	if (sin(game->ray.dir) > 0.001)
	{
		game->ray.y = (int)game->player.pos_y / TILE_SZ * TILE_SZ - 0.0001;
		game->ray.x = (game->player.pos_y - game->ray.y) \
		* rev_tan + game->player.pos_x;
		y = -TILE_SZ;
		x = -y * rev_tan;
	}
	else if (sin(game->ray.dir) < -0.001)
	{
		game->ray.y = (int)game->player.pos_y / TILE_SZ * TILE_SZ + TILE_SZ;
		game->ray.x = (game->player.pos_y - game->ray.y) \
		* rev_tan + game->player.pos_x;
		y = TILE_SZ;
		x = -y * rev_tan;
	}
	else
	{
		game->ray.x = game->player.pos_x;
		game->ray.y = game->player.pos_y;
		i = 8;
	}
	while (i < 8)
	{
		game->ray.hit_x = game->ray.x / TILE_SZ;
		game->ray.hit_y = game->ray.y / TILE_SZ;
		if (game->ray.hit_x >= 0 && game->ray.hit_y >= 0 && game->ray.hit_x <= \
		game->map.width && game->ray.hit_y <= game->map.height && game->map.map \
		[(int)game->ray.hit_y][(int)game->ray.hit_x] != 0)
		{
			game->ray.temp_hx = game->ray.x;
			game->ray.temp_hy = game->ray.y;
			game->ray.h_dist = cos(game->ray.dir) * (game->ray.x - game->player.pos_x) - \
			sin(game->ray.dir) * (game->ray.y - game->player.pos_y);
			i = 8;
		}
		else
		{
			game->ray.x += x;
			game->ray.y += y;
			i++;
		}
	}
}

// void	draw_line(t_game *game, double x, double y)
// {
// 	double	dx;
// 	double	dy;
// 	double	sx;
// 	double	sy;
// 	double	err;
// 	double	e2;

// 	dx = fabs(x - game->player.pos_x);
// 	dy = -fabs(y - game->player.pos_y);
// 	if (x < game->player.pos_x)
// 		sx = -1;
// 	else
// 		sx = 1;
// 	if (y < game->player.pos_y)
// 		sy = -1;
// 	else
// 		sy = 1;
// 	err = dx + dy;
// 	game->player.temp_x = game->player.pos_x;
// 	game->player.temp_y = game->player.pos_y;
// 	while (game->player.temp_x >= 0 && game->player.temp_y >= 0 && \
// 	game->player.temp_x < game->map.width * TILE_SZ && game->player.temp_y < \
// 	game->map.height * TILE_SZ)
// 	{
// 		printf("x: %f, y: %f\n", game->player.temp_x, game->player.temp_y);
// 		mlx_put_pixel(game->img, (int)game->player.temp_x, (int)game->player.temp_y, \
// 		get_rgba(255, 255, 0, 255));
// 		if (game->player.temp_x == x && game->player.temp_y == y)
// 			break ;
// 		e2 = 2 * err;
// 		if (e2 >= dy)
// 		{
// 			err += dy;
// 			game->player.temp_x += sx;
// 		}
// 		if (e2 <= dx)
// 		{
// 			err += dx;
// 			game->player.temp_y += sy;
// 		}
// 	}
// }

void	lin_interp(t_game *game, double x2, double y2)
{
	double	dx;
	double	dy;
	double	step;
	double	x;
	double	y;

	dx = x2 - game->player.pos_x;
	dy = y2 - game->player.pos_y;
	step = fabs(dx);
	if (fabs(dy) > step)
		step = fabs(dy);
	dx /= step;
	dy /= step;
	x = game->player.pos_x;
	y = game->player.pos_y;
	while ((int)(x - x2) || (int)(y - y2))
	{
		if ((int)x < game->map.width * TILE_SZ && (int)y < game->map.height * \
		TILE_SZ && (int)x > 0 && (int)y > 0 && game->map.map[(int)y / TILE_SZ] \
		[(int)x / TILE_SZ] == 0)
			mlx_put_pixel(game->img, x, y, get_rgba(0, 255, 126, 255));
		x += dx;
		y += dy;
	}
}

// void	draw_ray(t_game *game)
// {
// 	int		i;

// 	i = 0;
// 	game->ray.dir = game->player.dir - game->player.fov / 2;
// 	while (game->ray.dir < game->player.dir + game->player.fov / 2)
// 	{
// 		game->ray.x = game->player.pos_x + cos(game->ray.dir) * 100;
// 		game->ray.y = game->player.pos_y + sin(game->ray.dir) * 100;
// 		game->ray.dist = 0;
// 		while (game->ray.x < game->map.width * TILE_SZ \
// 		&& game->ray.y < game->map.height * TILE_SZ)
// 		{
// 			if (game->ray.x > 0 && game->ray.y > 0 && game->map.map[(int) \
// 			game->ray.y / TILE_SZ][(int)game->ray.x / TILE_SZ] != WALL)
// 			{
// 				game->ray.x += cos(game->ray.dir) * TILE_SZ;
// 				game->ray.y += sin(game->ray.dir) * TILE_SZ;
// 				game->ray.dist += TILE_SZ;
// 			}
// 			else
// 				break ;
// 		}
// 		lin_interp(game, game->ray.x, game->ray.y);
// 		game->ray.dir += 0.01;
// 		i++;
// 	}
// }



void	check_vertical_hit(t_game *game)
{
	double	x;
	double	y;
	double	tang;
	int		i;

	i = 0;
	game->ray.v_dist = 100000000000;
	tang = tan(game->ray.dir);
	// if (game->ray.dir > PI / 2 && game->ray.dir < 3 * PI / 2)
	if (cos(game->ray.dir) < -0.001)
	{
		game->ray.x = (int)game->player.pos_x / TILE_SZ * TILE_SZ - 0.0001;
		game->ray.y = (game->player.pos_x - game->ray.x) * tang + game->player.pos_y;
		x = -TILE_SZ;
		y = -x * tang;
	}
	else if (cos(game->ray.dir) > 0.001)
	{
		game->ray.x = (int)game->player.pos_x / TILE_SZ * TILE_SZ + TILE_SZ;
		game->ray.y = (game->player.pos_x - game->ray.x) * tang + game->player.pos_y;
		x = TILE_SZ;
		y = -x * tang;
	}
	else
	{
		game->ray.x = game->player.pos_x;
		game->ray.y = game->player.pos_y;
		i = 8;
	}
	while (i < 8)
	{
		game->ray.hit_x = game->ray.x / TILE_SZ;
		game->ray.hit_y = game->ray.y / TILE_SZ;
		if (game->ray.hit_x >= 0 && game->ray.hit_y >= 0 && game->ray.hit_x <= \
		game->map.width && game->ray.hit_y <= game->map.height && game->map.map \
		[(int)game->ray.hit_y][(int)game->ray.hit_x] != 0)
		{
			game->ray.temp_vx = game->ray.x;
			game->ray.temp_vy = game->ray.y;
			game->ray.v_dist = cos(game->ray.dir) * (game->ray.x - game->player.pos_x) + \
			- sin(game->ray.dir) * (game->ray.y - game->player.pos_y);
			i = 8;
		}
		else
		{
			game->ray.x += x;
			game->ray.y += y;
			i++;
		}
	}
}
