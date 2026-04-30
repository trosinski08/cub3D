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
	free_textures(game);
	free_map(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
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

void	free_textures(t_game *game)
{
	if (game->map.t_no)
		mlx_delete_texture(game->map.t_no);
	if (game->map.t_so)
		mlx_delete_texture(game->map.t_so);
	if (game->map.t_we)
		mlx_delete_texture(game->map.t_we);
	if (game->map.t_ea)
		mlx_delete_texture(game->map.t_ea);
	
	// Free texture path strings
	if (game->map.no)
		free(game->map.no);
	if (game->map.so)
		free(game->map.so);
	if (game->map.we)
		free(game->map.we);
	if (game->map.ea)
		free(game->map.ea);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map.map)
		return;
	i = 0;
	while (i < game->map.height)
		free(game->map.map[i++]);
	free(game->map.map);
}
