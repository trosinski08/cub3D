/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:14:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 15:44:14 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_player(t_game *game);
void			draw_ray(t_game *game);
int				ray_helper(t_game *game);
void			lin_interp(t_game *game, double x2, double y2);
void			draw_wall(t_game *game, int x, int flag);
mlx_texture_t	*set_texture_direction(t_game *game, int flag);
double			get_x_o(t_game *game, mlx_texture_t *texture, int flag);
unsigned int	reverse_bytes(int c);
void			draw_ceil(t_game *game, int x, int top_pixel);
void			draw_wall_helper(t_game *game, int x, int t_pixel, int b_pixel);

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
	int	screen_x;
	int	flag;

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
			flag = ray_helper(game);
		else
			lin_interp(game, game->ray.temp_vx, game->ray.temp_vy);
		game->ray.dir -= game->player.fov / WIDTH;
		draw_wall(game, screen_x++, flag);
	}
	game->draw_start = 0;
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int	ray_helper(t_game *game)
{
	lin_interp(game, game->ray.temp_hx, game->ray.temp_hy);
	game->ray.dist = game->ray.h_dist;
	return (1);
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
	step = fmax(fabs(dx), fabs(dy));
	dx /= step;
	dy /= step;
	x = game->player.pos_x;
	y = game->player.pos_y;
	while ((int)(x - x2) || (int)(y - y2))
	{
		if (x < game->map.width * TILE_SZ && y < game->map.height * TILE_SZ \
	&& x > 0 && y > 0 && game->map.map[(int)y / TILE_SZ][(int)x / TILE_SZ] == 0)
		{
			mlx_put_pixel(game->img, x, y, WALL_COLOR);
		}
		x += dx;
		y += dy;
	}
}

void	draw_wall(t_game *game, int x, int flag)
{
	t_tex			*texture;
	double			h;
	int				top_pixel;
	int				bottom_pixel;
	int				i;

	texture = (t_tex *)malloc(sizeof(t_tex));
	game->tex = texture;
	texture->addr = set_texture_direction(game, flag);
	texture->arr = (unsigned int *)texture->addr->pixels;
	h = (TILE_SZ / game->ray.dist) * ((WIDTH / 2) / tan(game->player.fov / 2));
	top_pixel = fmax(0, (HEIGHT / 2) - (h / 2));
	bottom_pixel = fmin(HEIGHT, (HEIGHT / 2) + (h / 2));
	texture->texture_step = (double)texture->addr->height / h;
	draw_ceil(game, x, top_pixel);
	texture->y_texture = 0;
	texture->x_texture = get_x_o(game, texture->addr, flag);
	draw_wall_helper(game, x, top_pixel, bottom_pixel);
	i = bottom_pixel;
	while (i < HEIGHT)
		mlx_put_pixel(game->img, x, i++, game->map.floor);
}

void	draw_wall_helper(t_game *game, int x, int top_pixel, int bottom_pixel)
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

void	draw_ceil(t_game *game, int x, int top_pixel)
{
	int	i;

	i = 0;
	while (i < top_pixel)
		mlx_put_pixel(game->img, x, i++, game->map.ceiling);
}

double	get_x_o(t_game *game, mlx_texture_t *texture, int flag)
{
	double	wall_hit;

	if (flag == 1)
		wall_hit = game->player.pos_x + game->ray.dist * cos(game->ray.dir);
	else
		wall_hit = game->player.pos_y + game->ray.dist * sin(game->ray.dir);
	return (fmod(wall_hit, TILE_SZ) / TILE_SZ * texture->width);
}

mlx_texture_t	*set_texture_direction(t_game *game, int flag)
{
	if (flag == 1)
	{
		if (game->ray.temp_hy > game->map.height * TILE_SZ / 2)
			return (game->map.t_no);
		else
			return (game->map.t_so);
	}
	else
	{
		if (game->ray.temp_vx > game->map.width * TILE_SZ / 2)
			return (game->map.t_ea);
		else
			return (game->map.t_we);
	}
}

unsigned int	reverse_bytes(int c)
{
	return (((c & 0x000000FF) << 24) | ((c & 0x0000FF00) << 8) \
	| ((c & 0x00FF0000) >> 8) | ((c & 0xFF000000) >> 24));
}
