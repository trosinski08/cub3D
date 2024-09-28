/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:19:20 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/28 22:09:14 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./MLX42/include/MLX42/MLX42.h"

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
	printf("GAME OVER\n");
	return (free_garb(), 0);
}

/*
- additional checks on map, if there is just one player, if every 
texture exist, if you have color of f and c start
if (open(map.no, O_DIRECTOIRY)  == -1)

- free all mallocs
-to imlement garb_collector
*/