/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:14:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 03:49:09 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

void			draw_player(t_game *game);
void			draw_ray(t_game *game);
void			lin_interp(t_game *game, double x2, double y2);
void			draw_wall(t_game *game, int x, int flag);
void			get_texture(t_game *game, int x, int y, int color);
mlx_texture_t	*set_texture_direction(t_game *game, int flag);
double			get_x_o(t_game *game, mlx_texture_t *texture, int flag);
unsigned int	reverse_bytes(int c);


void	draw_player(t_game *game)
{
	u_int32_t	color;
	int			x;
	int			y;

	color = get_rgba(255, 255, 0, 255);
	x = game->player.pos_x - 2;
	while (x < game->player.pos_x + 2)
	{
		y = game->player.pos_y - 2;
		while (y < game->player.pos_y + 2)
		{
			mlx_put_pixel(game->img, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_ray(t_game *game)
{
	int			screen_x;
	int			flag;

	screen_x = 0;
	if (game->draw_start == 0)
		return ;
	game->ray.dir = game->player.dir + game->player.fov / 2;
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	while (screen_x < WIDTH)
	{
		flag = 0;
		check_horizontal_hit(game);
		check_vertical_hit(game);
		game->ray.dist = game->ray.v_dist;
		if (game->ray.h_dist < game->ray.v_dist)
		{
			lin_interp(game, game->ray.temp_hx, game->ray.temp_hy);
			game->ray.dist = game->ray.h_dist;
			flag = 1;
		}
		else
			lin_interp(game, game->ray.temp_vx, game->ray.temp_vy);
		game->ray.dir -= game->player.fov / WIDTH;
		draw_wall(game, screen_x, flag);
		screen_x++;
	}
	game->draw_start = 0;
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

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

void	draw_wall(t_game *game, int x, int flag)
{
	double	h;
	double	b_pix;
	int		t_pix;
	double	x_o;
	double	y_o;
	int		i;
	mlx_texture_t	*texture;
	int		factor;
	u_int32_t	*arr;

	texture = set_texture_direction(game, flag);
	arr = (u_int32_t *)texture->pixels;
	game->ray.dist *= cos(fix_ang(game->ray.dir - game->player.dir));
	h = (TILE_SZ / game->ray.dist) * ((WIDTH / 2) / tan(game->player.fov / 2));
	factor = (double)texture->height / HEIGHT;
	b_pix = (HEIGHT / 2) + (h / 2);
	t_pix = (HEIGHT / 2) - (h / 2);
	x_o = get_x_o(game, texture, flag);
	y_o = (t_pix + (h / 2) - (HEIGHT / 2)) * factor;
	if (t_pix < 0)
		t_pix = 0;
	if (b_pix > WIDTH)
		b_pix = WIDTH;
	i = 0;
	if (x < TILE_SZ * game->map.width && t_pix < TILE_SZ * game->map.height)
		t_pix = TILE_SZ * game->map.height + 1;
	if (x < TILE_SZ * game->map.width)
		i = TILE_SZ * game->map.height + 1;
	while (i < t_pix)
		mlx_put_pixel(game->img, x, i++, game->map.ceiling);
	if (y_o < 0.1)
		y_o = 0.1;
	while (t_pix < b_pix)
	{
		y_o = fmax(0.1, y_o);
		i = (int)y_o * texture->width + (int)x_o;
		// printf("i: %d\n", i);
		if (i < (int)(texture->height * texture->width))
			mlx_put_pixel(game->img, x, t_pix, reverse_bytes(arr[i]));
		printf("x: %d\n", x);
		printf("t_pix: %d\n", t_pix);
		y_o += factor;
		t_pix++;
	}
	while (t_pix < HEIGHT)
		mlx_put_pixel(game->img, x, t_pix++, game->map.floor);
	flag = 0;
}

double	get_x_o(t_game *game, mlx_texture_t *texture, int flag)
{
	double	x_o;
	double	dist_to_wall;
	double	wall_hit_x;
	double	wall_hit_y;

	dist_to_wall = game->ray.dist;
	if (flag == 1)
	{
		wall_hit_x = game->player.pos_x + (dist_to_wall
				* cos(game->ray.dir));
		x_o = fmod(wall_hit_x, TILE_SZ) / TILE_SZ * texture->width;
	}
	else
	{
		wall_hit_y = game->player.pos_y + (dist_to_wall
				* sin(game->ray.dir));
		x_o = fmod(wall_hit_y, TILE_SZ) / TILE_SZ * texture->width;
	}
	return (x_o);
}


mlx_texture_t	*set_texture_direction(t_game *game, int flag)
{
	mlx_texture_t	*texture;

	if (flag == 1)
	{
		if (game->ray.temp_hy > game->map.height * TILE_SZ / 2)
			texture = game->map.t_no;
		else
			texture = game->map.t_so;
	}
	else
	{
		if (game->ray.temp_vx > game->map.width * TILE_SZ / 2)
			texture = game->map.t_ea;
		else
			texture = game->map.t_we;
	}
	return (texture);
}

unsigned int	reverse_bytes(int c)
{
	return (((c & 0x000000FF) << 24) | ((c & 0x0000FF00) << 8)
		| ((c & 0x00FF0000) >> 8) | ((c & 0xFF000000) >> 24));
}
