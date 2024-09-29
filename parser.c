/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:01:33 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/29 02:02:13 by trosinsk         ###   ########.fr       */
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

int		parser(t_game *game, char *file);
int		checker(t_game *game, int argc, char **argv);
void	parse_line(t_game *game, char *line);
char	**file_to_map(char *file, int lines);
int		check_if_map_is_valid(t_game *game);
// void	print_map(char **map);

int	parser(t_game *game, char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nFailed to open file\n"), 0);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(game, line);
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
			i++;
		free(line);
		line = get_next_line(fd);
	}
	map = file_to_map(file, i);
	if (i > 0)
		init_map(game, i, map);
	if (check_if_map_is_valid(game) == 0)
		return (0);
	set_texture(game);
	return (close(fd), free(line), free_arr(map), 1);
}

char	**file_to_map(char *file, int lines)
{
	char	*line;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * lines + 1);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
			map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

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
	return (1);
}

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	printf("//****************Map********************//\n");
// 	while (map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// 	printf("//***************************************//\n");
// }