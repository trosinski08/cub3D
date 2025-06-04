/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:00:00 by trosinsk          #+#    #+#             */
/*   Updated: 2024/12/04 20:00:00 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_map_lines(t_game *game, char *file);
int		process_parsed_data(t_game *game, char *file, int map_line_count);
char	**allocate_map_array(int lines);
void	read_map_lines(int fd, char **map, int lines);

int	count_map_lines(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		map_line_count;

	map_line_count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(game, line);
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
			map_line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_line_count);
}

int	process_parsed_data(t_game *game, char *file, int map_line_count)
{
	char	**map_lines;

	map_lines = file_to_map(file, map_line_count);
	if (map_line_count > 0)
		init_map(game, map_line_count, map_lines);
	if (check_if_map_is_valid(game) == 0)
		return (0);
	set_texture(game);
	free_arr(map_lines);
	return (1);
}

char	**allocate_map_array(int lines)
{
	char	**map;

	map = malloc(sizeof(char *) * (lines + 1));
	return (map);
}

void	read_map_lines(int fd, char **map, int lines)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && i < lines)
	{
		if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
			map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	map[i] = NULL;
}
