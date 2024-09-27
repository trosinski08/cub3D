/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:14:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/27 20:20:57 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_player(t_game *game);
void			draw_ray(t_game *game);
void			lin_interp(t_game *game, double x2, double y2);
void			draw_wall(t_game *game, int x, int flag);
void			get_texture(t_game *game, int x, int y, int color);
mlx_texture_t	*set_texture_direction(t_game *game, int flag);


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
	u_int32_t	color;
	int			flag;

	screen_x = 0;
	if (game->draw_start == 0)
		return ;
	flag = 0;
	game->ray.dir = game->player.dir + game->player.fov / 2;
	printf("img: %p\n", game->img);
	printf("mlx: %p\n", game->mlx);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	while (screen_x < WIDTH)
	{
		check_horizontal_hit(game);
		check_vertical_hit(game);
		color = get_rgba(255, 255, 0, 126);
		game->ray.dist = game->ray.v_dist;
		if (game->ray.h_dist < game->ray.v_dist)
		{
			lin_interp(game, game->ray.temp_hx, game->ray.temp_hy);
			color = get_rgba(0, 255, 255, 126);
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
	double	t_pix;
	int		i;

	game->ray.dist *= cos(fix_ang(game->ray.dir - game->player.dir));
	h = (TILE_SZ / game->ray.dist) * ((WIDTH / 8) / tan(game->player.fov / 2));
	b_pix = (HEIGHT / 2) + (h / 2);
	t_pix = (HEIGHT / 2) - (h / 2);
	if (t_pix < 0)
		t_pix = 0;
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	i = 0;
	if (x < TILE_SZ * game->map.width && t_pix < TILE_SZ * game->map.height)
		t_pix = TILE_SZ * game->map.height + 1;
	if (x < TILE_SZ * game->map.width)
		i = TILE_SZ * game->map.height + 1;
	while (i < t_pix)
		mlx_put_pixel(game->img, x, i++, game->map.ceiling);
	while (t_pix++ < b_pix)
		{mlx_put_pixel(game->img, x, t_pix, get_rgba(0, 255, 0, 255));
	// w tym miejscu potrzebuję zaimplementować tekstury
		get_texture(game, x, t_pix++, flag);}
	while (t_pix < HEIGHT)
		mlx_put_pixel(game->img, x, t_pix++, game->map.floor);
}
	// mlx_put_pixel(game->img, x, t_pix++, get_rgba(0, 0, 0, 255));
void	get_texture(t_game *game, int x, int y, int flag)
{
	mlx_texture_t	*texture;
	u_int32_t		color;
	int				x_o;
	int				y_o;

	texture = set_texture_direction(game, flag);
	printf("texture.width: %d\ntexture.height: %d\n", texture->width, texture->height);
	x_o = (int)(game->ray.hit_x * texture->width) % texture->width;
	y_o = (int)(game->ray.hit_y * texture->height) % texture->height;
	printf("\n\nx_o: %d\ny_o: %d\n\n", x_o, y_o);
	// printf("\n\ngame->player.dir: %f\n\n", game->player.dir);
	// i need to read the color from the texture
	// typedef struct mlx_texture
// {
	// uint32_t	width;
	// uint32_t	height;
	// uint8_t		bytes_per_pixel;
	// uint8_t*	pixels;
// }	mlx_texture_t;
	color = texture->pixels[y_o * texture->width + x_o];
	mlx_put_pixel(game->img, x, y, color);
}

mlx_texture_t	*set_texture_direction(t_game *game, int flag)
{
	mlx_texture_t	*texture;

//flag = 0 vertical distance is smaller;
//flag = 1 horizontal distance is smaller;
	game->map.t_no = mlx_load_png(game->map.no);
	game->map.t_so = mlx_load_png(game->map.so);
	game->map.t_we = mlx_load_png(game->map.we);
	game->map.t_ea = mlx_load_png(game->map.ea);
	if (flag == 0)
	{
		if (game->ray.dir > 0 && game->ray.dir < PI)
			texture = game->map.t_no;
		else
			texture = game->map.t_so;
	}
	else
	{
		if (game->ray.dir > PI / 2 && game->ray.dir < 3 * PI / 2)
			texture = game->map.t_ea;
		else
			texture = game->map.t_we;
	}
	printf("texture.width: %d\ntexture.height: %d\n", texture->width, texture->height);
	return (texture);
}
