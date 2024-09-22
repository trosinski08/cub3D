/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:15:23 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/22 15:28:03 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game		*init_game(void);
t_player	player_init(t_game *game);
mlx_t		*init_mlx(t_game *game);
void		print_map2(int **map);

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

void	init_map(t_game *game, int height, char **map_str)
{
	int		**map;
	int		i;
	int		j;

	game->map.width = ft_strlen(map_str[0]) - 1;
	map = (int **)malloc(sizeof(int *) * height);
	if (!map)
		return (printf("Error\nFailed to allocate memory\n"), (void) NULL);
	i = -1;
	while (++i <= height)
	{
		map[i] = (int *)malloc(sizeof(int) * game->map.width);
		if (!map[i])
			return (printf("Error\nFailed to allocate memory\n"), (void) NULL);
	}
	game->map.map = map;
	game->map.height = height;
	i = -1;
	while (++i < height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (j > game->map.width)
				game->map.width = j - 1;
			if (map_str[i][j] == ' ')
				map[i][j] = 2;
			else if (map_str[i][j] == '1' || map_str[i][j] == '0')
				map[i][j] = map_str[i][j] - '0';
			else if (map_str[i][j] == 'N' || map_str[i][j] == 'W' || \
			map_str[i][j] == 'E' || map_str[i][j] == 'S')
			{
				map[i][j] = 3;
				game->map.player_x = j;
				game->map.player_y = i;
				game->map.player_dir = map_str[i][j];
				if (map_str[i][j] == 'S')
					game->player.dir = PI / 2;
				else if (map_str[i][j] == 'W')
					game->player.dir = PI;
				else if (map_str[i][j] == 'N')
					game->player.dir = 3 * PI / 2;
				else if (map_str[i][j] == 'E')
					game->player.dir = 0;
			}
			else
				map[i][j] = -1;
			j++;
		}
	}
	game->player = player_init(game);
}

void	print_map2(int **map)
{
	int	i;
	int	j;

	i = -1;
	printf("//****************Map********************//\n");
	while (++i < 21)
	{
		j = 0;
		while (j < 21)
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
	}
	printf("//***************************************//\n");
}

t_player	player_init(t_game *game)
{
	t_player	player;

	player = game->player;
	player.fov = FOV * M_PI / 180;
	player.pos_x = ((game->map.player_x) * TILE_SZ) + TILE_SZ / 2;
	player.pos_y = ((game->map.player_y) * TILE_SZ) + TILE_SZ / 2;
	player.p_delta_x = cos(player.dir) * 5;
	player.p_delta_y = sin(player.dir) * 5;
	printf("Player position: x: %f, y: %f\n", player.pos_x, player.pos_y);
	printf("Player direction: %f\n", player.dir);
	printf("Player angle: %f\n", player.player_angle);
	printf("Player delta x: %f, delta y: %f\n", player.p_delta_x, player.p_delta_y);
	printf("Player fov: %f\n", player.fov);
	printf("Map direction: %c\n", game->map.player_dir);
	return (player);
}
