/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:00:20 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 17:12:32 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "libft/include/libft.h"
# include "./gnl42/include/get_next_line.h"
// # include "MLX42.h"

# define WALL 1
# define EMPTY 0
# define PLAYER 3
# define PI 3.14159265359
# define FOV 45
# define SPEED 0.1
# define ROTATE 0.1
# define MINIMAP_SCALE 0.2
# define MINIMAP_SIZE 10
# define TILE_SZ 16
# define TILE_SCALE 0.2
# define WIDTH 1920
# define HEIGHT 1080
# define BPP 4
# define PLAYER_COLOR 0xFFFF00
# define WALL_COLOR 0x00FFFFFF

typedef struct s_map
{
	mlx_texture_t	*t_no;
	mlx_texture_t	*t_so;
	mlx_texture_t	*t_we;
	mlx_texture_t	*t_ea;
	int				**map;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	int				player_dir;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				floor;
	int				ceiling;
}				t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	temp_x;
	double	temp_y;
	double	fov;
	double	p_delta_x;
	double	p_delta_y;
	double	dir;
}				t_player;

typedef struct s_ray
{
	double	x;
	double	hit_x;
	double	temp_hx;
	double	temp_x;
	double	temp_vx;
	double	y;
	double	hit_y;
	double	temp_y;
	double	temp_hy;
	double	temp_vy;
	double	dir;
	double	dist;
	double	h_dist;
	double	v_dist;
	int		is_vertical_hit;
}				t_ray;

typedef struct s_tex
{
	mlx_texture_t	*addr;
	unsigned int	*arr;
	double			texture_step;
	double			x_texture;
	double			y_texture;
	int				tex_index;
}			t_tex;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_tex		*tex;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			draw_start;
	int			enter_flag;
	int			mini_flag;
}				t_game;

// init
t_game		*init_game(void);
mlx_t		*init_mlx(t_game *game);
void		init_map(t_game *game, int height, char **map_str);
void		my_keyhook(mlx_key_data_t keydata, void *param);

// parser
int			parser(t_game *game, char *file);
void		parse_texture(t_game *game, char *line);
void		parse_color(t_game *game, char *line);
void		parse_map(t_game *game, char *line);
int			checker(t_game *game, int argc, char **argv);
int			check_if_walls_are_closed(t_game *game);

//setters
void		set_player(t_game *game, int i, int j, char dir);
void		set_map(t_game *game, int i, int j, char *line);
void		set_texture(t_game *game);

//draw
void		new_game(void *param);
void		draw_player(t_game *game);
void		draw_mini_map(t_game *game);
void		draw_wall(t_game *game, int x, int top_pixel, int bottom_pixel);
void		draw_line(t_game *game, int x2, int y2);

//raytrace
void		raytrace(t_game *game);
void		check_vertical_hit(t_game *game);
void		check_horizontal_hit(t_game *game);
void		render(t_game *game, int x, int flag);

//utils
double		fix_ang(double a);
u_int32_t	get_rgba(int r, int g, int b, int a);
void		fill_with_color(mlx_image_t *img, u_int32_t color, \
			u_int32_t color2);
u_int32_t	reverse_bytes(int c);
int			free_garb(void);
void		draw_ceil(t_game *game, int x, int top_pixel);

#endif