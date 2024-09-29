/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:20:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/29 02:06:27 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player(t_game *game, int i, int j, char dir);
void	set_map(t_game *game, int i, int j, char *line);
void	set_texture(t_game *game);

void	set_player(t_game *game, int i, int j, char dir)
{
	game->map.map[i][j] = 0;
	game->map.player_x = j;
	game->map.player_y = i;
	game->map.player_dir = dir;
	if (dir == 'N')
		game->player.dir = PI / 2;
	else if (dir == 'W')
		game->player.dir = PI;
	else if (dir == 'S')
		game->player.dir = 3 * PI / 2;
	else if (dir == 'E')
		game->player.dir = 0;
}

void	set_map(t_game *game, int i, int j, char *line)
{
	if (j > game->map.width)
		game->map.width = j - 1;
	if (line[j] == ' ')
	{
		if (i == 0 || i == game->map.height || j == 0 || \
		j == game->map.width || (game->map.map[i][j + 1] && \
		game->map.map[i][j + 1] == 1) || (game->map.map[i][j - 1] && \
		game->map.map[i][j - 1] == 1))
			game->map.map[i][j] = 1;
		else
			game->map.map[i][j] = 0;
	}
	else if (line[j] == '1' || line[j] == '0')
		game->map.map[i][j] = line[j] - '0';
	else if (line[j] == 'N' || line[j] == 'W' || line[j] == 'E' \
	|| line[j] == 'S')
		set_player(game, i, j, line[j]);
	else
		game->map.map[i][j] = -1;
}

void	set_texture(t_game *game)
{
	if (!game->map.no || !game->map.so || !game->map.we || !game->map.ea)
	{
		printf("Error\nMissing texture\n");
		exit(0);
	}
	if (!mlx_load_png(game->map.no) || !mlx_load_png(game->map.so) || \
	!mlx_load_png(game->map.we) || !mlx_load_png(game->map.ea))
	{
		printf("Error\nInvalid texture file\n");
		exit(0);
	}
	game->map.t_no = mlx_load_png(game->map.no);
	game->map.t_so = mlx_load_png(game->map.so);
	game->map.t_we = mlx_load_png(game->map.we);
	game->map.t_ea = mlx_load_png(game->map.ea);
	free(game->map.no);
	free(game->map.so);
	free(game->map.we);
	free(game->map.ea);
}
