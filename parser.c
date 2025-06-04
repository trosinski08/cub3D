/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:01:33 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/29 02:50:19 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** 
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
#include "cub3d.h"

int			parser(t_game *game, char *file);
char		**file_to_map(char *file, int lines);

int	parser(t_game *game, char *file)
{
	int	map_line_count;

	map_line_count = count_map_lines(game, file);
	if (map_line_count == -1)
		return (printf("Error\nFailed to open file\n"), 0);
	return (process_parsed_data(game, file, map_line_count));
}

char	**file_to_map(char *file, int lines)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = allocate_map_array(lines);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	read_map_lines(fd, map, lines);
	close(fd);
	return (map);
}
