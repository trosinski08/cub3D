/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:02:44 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/29 00:48:15 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_garb(t_game *game);
void	free_map(t_game *game);

int	free_garb(t_game *game)
{
	free_map(game);
	free(game);
	return (1);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
		free(game->map.map[i++]);
	free(game->map.map);
}
