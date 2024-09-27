/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trosinsk <trosinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:48:44 by trosinsk          #+#    #+#             */
/*   Updated: 2024/09/27 01:31:25 by trosinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_texture(t_game *game, char *line);
void	parse_color(t_game *game, char *line);
void	parse_map(t_game *game, char *line);
// void	parse_resolution(t_game *game, char *line);

void	parse_texture(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		game->map.no = ft_strdup(line + 3);
	else if (line[0] == 'S' && line[1] == 'O')
		game->map.so = ft_strdup(line + 3);
	else if (line[0] == 'W' && line[1] == 'E')
		game->map.we = ft_strdup(line + 3);
	else if (line[0] == 'E' && line[1] == 'A')
		game->map.ea = ft_strdup(line + 3);
}
//add check if texture is valid directory and xpm file

void	parse_color(t_game *game, char *line)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = 1;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ' || line[i] == ',')
		i++;
	g = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ' || line[i] == ',')
		i++;
	b = ft_atoi(line + i);
	if (line[0] == 'F')
		game->map.floor = get_rgba(r, g, b, 255);
	else if (line[0] == 'C')
		game->map.ceiling = get_rgba(r, g, b, 255);
}
//add check if color is valid and if there are no other characters

void	parse_map(t_game *game, char *line)
{
	(void)game;
	while (*line)
	{
		if (*line == '1' || *line == '0' || *line == ' ' || *line == '\n')
			line++;
		else if (*line == 'N' || *line == 'W' || *line == 'E' || *line == 'S')
			line++;
		else
			printf("Error\nInvalid character in map\n");
	}
}

