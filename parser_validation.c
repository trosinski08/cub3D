/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:00:00 by trosinsk          #+#    #+#             */
/*   Updated: 2024/12/04 20:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checker(t_game *game, int argc, char **argv);
void	parse_line(t_game *game, char *line);
int		check_if_map_is_valid(t_game *game);

int	checker(t_game *game, int argc, char **argv)
{
	if (argc == 1)
		return (printf("Error\nNo arguments given\n"), 0);
	else if (argc > 2)
		return (printf("Error\nToo many arguments\n"), 0);
	if (argv[1] && (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, \
".cub", 4) != 0) && ft_strlen(argv[1]) > 4)
		return (printf("Error\nInvalid file extension\n"), 0);
	if (open(argv[1], O_RDONLY) == -1)
		return (printf("Error\nFailed to open file\n"), 0);
	if (parser(game, argv[1]) == 0)
		return (printf("Map parsing failed\n"), 0);
	return (1);
}

void	parse_line(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		parse_texture(game, line);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_texture(game, line);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_texture(game, line);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_texture(game, line);
	else if (line[0] == 'F')
		parse_color(game, line);
	else if (line[0] == 'C')
		parse_color(game, line);
	else if (line[0] == '1' || line[0] == '0')
		parse_map(game, line);
	else if (line[0] == '\0' || line[0] == '\n' || line[0] == ' ')
		return ;
	else
		printf("Error\nInvalid line in file\n");
}

int	check_if_map_is_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 0)
			{
				if (i == 0 || i == game->map.height - 1)
					return (printf("Error\nMap is not closed\n"), 0);
				else if (j == 0 || j == game->map.width - 1)
					return (printf("Error\nMap is not closed\n"), 0);
			}
			j++;
		}
		i++;
	}
	if (game->map.map_player_count != 1)
		return (printf("Error\nInvalid number of players\n"), 0);
	return (1);
}
