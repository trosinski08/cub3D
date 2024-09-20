/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:15:23 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/20 23:39:10 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		*init_game(void);
t_player	player_init(t_game *game);
mlx_t		*init_mlx(t_game *game);

mlx_t	*init_mlx(t_game *game)
{
	mlx_image_t	*img;
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!mlx)
		return (printf("Error\nFailed to initialize MLX\n"), NULL);
	game->mlx = mlx;
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	game->img = img;
	mlx_put_string(mlx, "Cub3D in progres!", WIDTH / 2 - 150, HEIGHT / 2 - 20);
	mlx_put_string(mlx, "Press ESC to exit or Enter to continue\n:)", \
	WIDTH / 2 - 150, HEIGHT / 2 + 20);
	return (mlx);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (printf("Error\nFailed to allocate memory\n"), NULL);
	game->map.width = 0;
	game->map.height = 0;
	game->map.map = NULL;
	game->player = player_init(game);
	game->ray = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->addr = NULL;
	game->bpp = 0;
	game->line_len = 0;
	game->endian = 0;
	game->color = 0;
	game->draw_start = 0;
	game->enter_flag = 0;
	game->mini_flag = 0;
	return (game);
}

void	init_map(t_game *game, int height, int width, char **map_str)
{
	int		**map;
	int		i;
	int		j;

	map = malloc(sizeof(int *) * height + 1);
	if (!map)
		printf("Error\nFailed to allocate memory\n");
	i = -1;
	while (++i <= height)
	{
		map[i] = malloc(sizeof(int) * width + 1);
		if (!map[i])
			printf("Error\nFailed to allocate memory\n");
	}
	game->map.map = map;
	game->map.width = width + 1;
	game->map.height = height + 1;
	i = -1;
	while (map_str[++i])
	{
		j = -1;
		while (map_str[i][++j] && map_str[i][j] != '\n')
			map[i][j] = map_str[i][j] - '0';
	}
}


t_player	player_init(t_game *game)
{
	t_player	player;

	(void)game;
	player.fov = FOV;
	player.player_angle = 0;
	player.pos_x = WIDTH / 2;
	player.pos_y = HEIGHT / 2;
	player.dir = 0;
	player.p_delta_x = cos(player.dir) * 5;
	player.p_delta_y = sin(player.dir) * 5;
	return (player);
}
