/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:00:00 by trosinsk          #+#    #+#             */
/*   Updated: 2024/12/04 20:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		**allocate_map_memory(int height, int width);
void	populate_map(t_game *game, int height, char **map_str);

int	**allocate_map_memory(int height, int width)
{
	int	**map;
	int	i;

	map = (int **)malloc(sizeof(int *) * height);
	if (!map)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		map[i] = (int *)malloc(sizeof(int) * width);
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
	}
	return (map);
}

void	populate_map(t_game *game, int height, char **map_str)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = 0;
		while (j < game->map.width)
			set_map(game, i, j++, map_str[i]);
	}
}
