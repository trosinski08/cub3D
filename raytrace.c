/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:14:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 21:09:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			raytrace(t_game *game);
void			render(t_game *game, int x, int flag);
mlx_texture_t	*set_texture_direction(t_game *game, int flag);
double			get_x_o(t_game *game, mlx_texture_t *texture, int flag);

void	raytrace(t_game *game)
{
	int	screen_x;
	int	flag;

	screen_x = 0;
	if (game->draw_start == 0)
		return ;
	game->ray.dir = fix_ang(game->player.dir + game->player.fov / 2);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	while (screen_x < WIDTH)
	{
		flag = 0;
		check_vertical_hit(game);
		check_horizontal_hit(game);
		game->ray.dist = fmin(game->ray.h_dist, game->ray.v_dist);
		if (fmin(game->ray.h_dist, game->ray.v_dist) == game->ray.h_dist)
			flag = 1;
		game->ray.dir -= game->player.fov / WIDTH;
		game->ray.dir = fix_ang(game->ray.dir);
		render(game, screen_x++, flag);
	}
	game->draw_start = 0;
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	render(t_game *game, int x, int flag)
{
	t_tex			*texture;
	int				h;
	int				top_pixel;
	int				bottom_pixel;
	int				i;

	game->ray.dist *= cos(fix_ang(game->player.dir - game->ray.dir));
	texture = (t_tex *)malloc(sizeof(t_tex));
	game->tex = texture;
	texture->addr = set_texture_direction(game, flag);
	texture->arr = (unsigned int *)texture->addr->pixels;
	h = (TILE_SZ / game->ray.dist) * ((WIDTH / 2) / tan(game->player.fov / 2));
	texture->h = h;
	top_pixel = fmax(0, (HEIGHT / 2) - (h / 2));
	bottom_pixel = fmin(HEIGHT, (HEIGHT / 2) + (h / 2));
	texture->texture_step = (double)texture->addr->height / h;
	draw_ceil(game, x, top_pixel);
	texture->y_texture = 0;
	texture->x_texture = get_x_o(game, texture->addr, flag);
	draw_wall(game, x, top_pixel, bottom_pixel);
	i = bottom_pixel;
	while (i < HEIGHT)
		mlx_put_pixel(game->img, x, i++, game->map.floor);
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

void	draw_wall(t_game *game, int x, int top_pixel, int bottom_pixel)
{
	t_tex	*texture;
	int		i;

	texture = game->tex;
	i = HEIGHT / 2 - texture->h / 2;
	while (i < bottom_pixel)
	{
		texture->tex_index = (int)texture->y_texture * texture->addr->width + \
		(int)texture->x_texture;
		if (texture->tex_index < texture->addr->width * \
	texture->addr->height && i >= top_pixel)
			mlx_put_pixel(game->img, x, i, \
			reverse_bytes(texture->arr[texture->tex_index]));
		texture->y_texture += texture->texture_step;
		i++;
	}
}
