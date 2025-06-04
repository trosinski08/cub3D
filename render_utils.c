/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:00:00 by trosinsk          #+#    #+#             */
/*   Updated: 2024/12/04 12:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calculate texture X coordinate based on wall hit position
** @param game: game structure with ray information
** @param texture: texture to map
** @param flag: wall orientation flag (1=horizontal, 0=vertical)
** @return: X coordinate in texture space
*/
double	get_x_o(t_game *game, mlx_texture_t *texture, int flag)
{
	double	wall_hit;
	double	texture_x;
	double	result;

	if (flag == 1)
		wall_hit = game->ray.temp_hx;
	else
		wall_hit = game->ray.temp_vy;
	texture_x = fmod(wall_hit, (double)TILE_SZ) / TILE_SZ;
	if (texture_x < 0)
		texture_x += 1.0;
	result = texture_x * (double)texture->width;
	if (result >= texture->width)
		result = texture->width - 1;
	if (result < 0)
		result = 0;
	return (result);
}

/*
** Determine wall texture based on ray direction and hit type
** @param game: game structure with ray direction
** @param flag: wall hit type (1=horizontal, 0=vertical)
** @return: pointer to appropriate texture
*/
mlx_texture_t	*set_texture_direction(t_game *game, int flag)
{
	if (flag == 1)
	{
		if (sin(game->ray.dir) < 0)
			return (game->map.t_so);
		else
			return (game->map.t_no);
	}
	else
	{
		if (cos(game->ray.dir) < 0)
			return (game->map.t_ea);
		else
			return (game->map.t_we);
	}
}

/*
** Draw pixel if texture coordinates are valid
** @param game: game structure
** @param texture: texture information
** @param x: screen X coordinate
** @param i: screen Y coordinate
*/
static void	put_texture_pixel(t_game *game, t_tex *texture, int x, int i)
{
	int	tex_y;
	int	tex_x;

	tex_y = (int)texture->y_texture;
	if (tex_y >= 0 && tex_y < (int)texture->addr->height)
	{
		tex_x = (int)texture->x_texture;
		if (tex_x >= 0 && tex_x < (int)texture->addr->width)
		{
			texture->tex_index = tex_y * (int)texture->addr->width + tex_x;
			if (texture->tex_index < (texture->addr->width
					* texture->addr->height))
				mlx_put_pixel(game->img, x, i,
					reverse_bytes(texture->arr[texture->tex_index]));
		}
	}
}

/*
** Optimized wall drawing function with bounds checking
** @param game: game structure
** @param texture: texture information
** @param params: rendering parameters (x, top_pixel, bottom_pixel)
*/
void	draw_wall_optimized(t_game *game, t_tex *texture,
		t_render_params *params)
{
	int	i;

	i = HEIGHT / 2 - texture->h / 2;
	texture->y_texture = 0;
	if (i < 0)
	{
		texture->y_texture = -i * texture->texture_step;
		i = 0;
	}
	while (i < params->bottom_pixel && i < HEIGHT)
	{
		if (i >= params->top_pixel)
			put_texture_pixel(game, texture, params->x, i);
		texture->y_texture += texture->texture_step;
		i++;
	}
}
