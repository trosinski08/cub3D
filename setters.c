/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:20:26 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/27 01:45:03 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_player(t_game *game, int i, int j, char dir);
void		set_map(t_game *game, int i, int j, char *line);

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
		game->map.map[i][j] = 2;
	else if (line[j] == '1' || line[j] == '0')
		game->map.map[i][j] = line[j] - '0';
	else if (line[j] == 'N' || line[j] == 'W' || line[j] == 'E' \
	|| line[j] == 'S')
		set_player(game, i, j, line[j]);
	else
		game->map.map[i][j] = -1;
}
