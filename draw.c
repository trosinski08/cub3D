/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:58:36 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 17:29:46 by trosinsk         ###   ########.fr       */
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

void	draw_wall(t_game *game, int x, int top_pixel, int bottom_pixel)
{
	t_tex	*texture;
	int		i;

	i = top_pixel;
	texture = game->tex;
	while (i < bottom_pixel)
	{
		texture->tex_index = (int)texture->y_texture * texture->addr->width + \
		(int)texture->x_texture;
		if ((u_int32_t)texture->tex_index < texture->addr->width * \
	texture->addr->height)
			mlx_put_pixel(game->img, x, i, \
			reverse_bytes(texture->arr[texture->tex_index]));
		texture->y_texture += texture->texture_step;
		i++;
	}
}

// void	draw_line(t_game *game, int x2, int y2)
// {
// 	double	dx;
// 	double	dy;
// 	double	step;
// 	double	x;
// 	double	y;

// 	dx = x2 - game->player.pos_x;
// 	dy = y2 - game->player.pos_y;
// 	step = fmax(fabs(dx), fabs(dy));
// 	dx /= step;
// 	dy /= step;
// 	x = game->player.pos_x;
// 	y = game->player.pos_y;
// 	while ((int)(x - x2) || (int)(y - y2))
// 	{
// 		if (x < game->map.width * TILE_SZ && y < game->map.height * TILE_SZ \
// 	&& x > 0 && y > 0 && game->map.map[(int)y / TILE_SZ][(int)x / TILE_SZ] == 0)
// 		{
// 			mlx_put_pixel(game->img, x, y, WALL_COLOR);
// 		}
// 		x += dx;
// 		y += dy;
// 	}
// }
void draw_line(t_game *game, int x2, int y2)
{
	int x = game->player.pos_x;
	int y = game->player.pos_y;
	int dx = abs(x2 - x);
	int dy = abs(y2 - y);
	int sx = x < x2 ? 1 : -1;  // Kierunek poruszania się po osi x
	int sy = y < y2 ? 1 : -1;  // Kierunek poruszania się po osi y
	int err = dx - dy;         // Błąd początkowy

	while (x != x2 || y != y2)
	{
		// Sprawdzanie, czy jesteśmy w granicach mapy i czy możemy rysować piksel
		if (x >= 0 && y >= 0 && x < game->map.width * TILE_SZ 
			&& y < game->map.height * TILE_SZ 
			&& game->map.map[y / TILE_SZ][x / TILE_SZ] == 0)
		{
			mlx_put_pixel(game->img, x, y, WALL_COLOR);
		}
		else
			break ;
		// Aktualizacja błędu i przesunięcie pozycji
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
	game->draw_start = 1;
}


// u_int32_t	check_hit(t_game *game)
// {
// 	u_int32_t	color;

// 	check_horizontal_hit(game);
// 	check_vertical_hit(game);
// 	if (game->ray.h_dist < game->ray.v_dist)
// 	{
// 		lin_interp(game, game->ray.temp_hx, game->ray.temp_hy);
// 		game->ray.dist = game->ray.h_dist;
// 		color = get_rgba(126, 126, 126, 126);
// 	}
// 	else
// 	{
// 		lin_interp(game, game->ray.temp_vx, game->ray.temp_vy);
// 		game->ray.dist = game->ray.v_dist;
// 		color = get_rgba(126, 126, 126, 255);
// 	}
// 	game->mini_flag = 0;
// 	return (color);
// }
