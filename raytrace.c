/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:14:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/12/04 12:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Main raycasting function - traces rays across screen width
** @param game: game structure containing all necessary data
*/
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

/*
** Initialize texture structure for rendering
** @param texture: texture structure to initialize
** @param game: game structure
** @param flag: wall orientation flag
*/
static void	init_texture(t_tex *texture, t_game *game, int flag)
{
	int	h;

	texture->addr = set_texture_direction(game, flag);
	texture->arr = (unsigned int *)texture->addr->pixels;
	h = (TILE_SZ / game->ray.dist) * ((WIDTH / 2) / tan(game->player.fov / 2));
	texture->h = h;
	texture->texture_step = (double)texture->addr->height / h;
	texture->y_texture = 0;
	texture->x_texture = get_x_o(game, texture->addr, flag);
}

/*
** Render single screen column with ceiling, wall, and floor
** @param game: game structure
** @param x: screen X coordinate
** @param flag: wall orientation (1=horizontal, 0=vertical)
*/
void	render(t_game *game, int x, int flag)
{
	t_tex				texture;
	t_render_params		params;
	int					i;

	game->ray.dist *= cos(fix_ang(game->player.dir - game->ray.dir));
	init_texture(&texture, game, flag);
	params.x = x;
	params.top_pixel = fmax(0, (HEIGHT / 2) - (texture.h / 2));
	params.bottom_pixel = fmin(HEIGHT, (HEIGHT / 2) + (texture.h / 2));
	draw_ceil(game, x, params.top_pixel);
	draw_wall_optimized(game, &texture, &params);
	i = params.bottom_pixel;
	while (i < HEIGHT)
		mlx_put_pixel(game->img, x, i++, game->map.floor);
}
