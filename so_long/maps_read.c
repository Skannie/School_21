/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:36:51 by kannie            #+#    #+#             */
/*   Updated: 2022/04/05 16:55:44 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_map(t_game *game)
{
	get_imgs(game);
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			50 * game->map.map_width, 50 * game->map.map_height, "so_long");
	img_to_maps(game);
}

int	check_map(t_map *map, t_game *game)
{
	int	i;

	i = check_wall(map);
	if (i != 1)
		print_exit("Wrong map walls!");
	i = check_valid_char(map, "10PEC", 0);
	if (i != 1)
		print_exit("Unknown symbol!");
	i = check_char(map, 'P', 0, game);
	if (i != 1)
		print_exit("No player position!");
	i = check_char(map, 'E', 0, game);
	if (i != 1)
		print_exit("No exit!");
	i = check_char(map, 'C', 0, game);
	if (i != 1)
		print_exit("No coin!");
	return (i);
}

int	record_map(t_map *map, char *name_map)
{
	int		i;

	i = 0;
	map->fd = open(name_map, O_RDONLY);
	map->map = (char **) malloc (sizeof(char *) * (map->map_height + 1));
	if (!map->map)
		return (-1);
	map->map[map->map_height] = NULL;
	while (map->map_height > i)
	{
		map->map[i] = get_next_line(map->fd);
		i++;
	}
	close(map->fd);
	return (1);
}

int	size_map(t_map	*map, char *name_map)
{
	int		i;

	map->map_width = 0;
	map->fd = open(name_map, O_RDONLY);
	if (map->fd == -1)
		return (-1);
	map->line = get_next_line(map->fd);
	if (map->line == NULL)
		return (-1);
	map->map_height = 1;
	while (map->line)
	{
		i = ft_strlen(map->line);
		if (map->map_width == 0)
			map->map_width = i;
		if (i != map->map_width)
			return (-1);
		map->buf = map->line;
		map->line = get_next_line(map->fd);
		free (map->buf);
		if (map->line)
			map->map_height++;
	}
	close(map->fd);
	return (1);
}

int	initial_check_map(t_game *game, char *name_map)
{
	int	i;

	game->map.map = NULL;
	i = size_map(&game->map, name_map);
	if (i != 1)
		print_exit("Wrong map!");
	i = record_map(&game->map, name_map);
	if (i != 1)
		print_exit("Wrong map!");
	i = check_map(&game->map, game);
	if (i != 1)
		print_exit("Wrong map!");
	return (i);
}
