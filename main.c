/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:19:20 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/20 00:10:16 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./MLX42/include/MLX42/MLX42.h"

/*
Your program must take as a first argument a scene description file with the .cub
extension.
◦ The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.
This is a simple valid map:
111111
100101
101001
1100N1
111111
◦ The map must be closed/surrounded by walls, if not the program must return
an error.
◦ Except for the map content, each type of element can be separated by one or
more empty line(s).
◦ Except for the map content which always has to be the last, each type of
element can be set in any order in the file.
◦ Except for the map, each type of information from an element can be separated
by one or more space(s).
◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.
7
cub3D My first RayCast
*/

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_game	*game;

	game = init_game();
	if (checker(game, argc, argv) == 0)
		return (free_garb(), 0);
	mlx = init_mlx(game);
	mlx_key_hook(mlx, &my_keyhook, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (free_garb(), 0);
}
