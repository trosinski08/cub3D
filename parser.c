/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:01:33 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/20 19:44:07 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_parser(t_game *game, char *file);
int		checker(t_game *game, int argc, char **argv);
void	print_map(char **map);


int	map_parser(t_game *game, char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;
	int		max_len;

	i = 0;
	max_len = -1;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (printf("Error\nFailed to allocate memory\n"), 0);	
	if (fd == -1)
		return (printf("Error\nFailed to open file\n"), 0);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		if ((int)ft_strlen(line) > max_len)
			max_len = ft_strlen(line) - 1;
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (i > 0)
		init_map(game, i - 1, max_len - 1, map);
	while (++i < 100)
	{
		free(map[i]);
	}
	return (free(line), 1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
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
	if (map_parser(game, argv[1]) == 0)
		return (printf("Map parsing failed\n"), 0);
	return (1);
}
