/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:19:20 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/22 14:38:37 by trosinsk         ###   ########.fr       */
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
	return (free_garb(), 0);
}


/*
-mala mapa w lewym gornym rogu, ma pokazywac okreslony wymiar
-W S A D zalezne od kierunku patrzenia
-staly rozmiar elementow jednak potrzebny, lekko popraw logike
popracuj nad parsingiem i checkami
-zaimplementuj garb_collector
*/