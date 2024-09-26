/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:00:20 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/26 22:02:42 by trosinsk         ###   ########.fr       */
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
# define FOV 60
# define SPEED 0.1
# define ROTATE 0.1
# define MINIMAP_SCALE 0.2
# define MINIMAP_SIZE 10
# define TILE_SZ 16
# define TILE_SCALE 0.2
# define WIDTH 1920
# define HEIGHT 1080
# define BPP 4

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_dir;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		floor;
	int		ceiling;
}				t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	temp_x;
	double	temp_y;
	double	fov;
	double	player_angle;
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
}				t_ray;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_ray		ray;
	mlx_t		*mlx;
	void		*win;
	mlx_image_t	*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			color;
	int			draw_start;
	int			enter_flag;
	int			mini_flag;
}				t_game;

void		my_keyhook(mlx_key_data_t keydata, void *param);
void		new_image(void *param);
int			free_garb(void);
int			checker(t_game *game, int argc, char **argv);
int			parser(t_game *game, char *file);
u_int32_t	get_rgba(int r, int g, int b, int a);
void		draw_player(t_game *game);
t_game		*init_game(void);
mlx_t		*init_mlx(t_game *game);
void		init_map(t_game *game, int height, char **map_str);
void		parse_texture(t_game *game, char *line);
void		parse_color(t_game *game, char *line);
void		parse_map(t_game *game, char *line);
void		fill_with_color(mlx_image_t *img, u_int32_t color, \
			u_int32_t color2);
void		set_player(t_game *game, int i, int j, char dir);
void		set_map(t_game *game, int i, int j, char *line);
void		check_vertical_hit(t_game *game);
void		check_horizontal_hit(t_game *game);
double		fix_ang(double a);
void		draw_ray(t_game *game);
void		draw_wall(t_game *game, int x, u_int32_t color);
void		draw_mini_map(t_game *game);
void		lin_interp(t_game *game, double x2, double y2);
void		check_horizontal_hit(t_game *game);
void		check_vertical_hit(t_game *game);

// void	parse_resolution(t_game *game, char *line);

#endif