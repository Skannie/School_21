/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:56:37 by kannie            #+#    #+#             */
/*   Updated: 2022/04/05 00:27:28 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strstr(char *str1, char *str2)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str1) - 4;
	j = ft_strlen(str2) - 4;
	while (str2[j] != '\0')
	{
		if (str1[i] != str2[j])
			return (-1);
		j++;
		i++;
	}
	if (str2[j] == '\0')
		return (1);
	return (-1);
}

int	check_ber(char *str)
{
	int	i;

	if (ft_strlen(str) > 4)
	{
		i = ft_strstr(str, ".ber");
		if (i == 1)
			return (1);
	}
	return (-1);
}

int	check_wall(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\0')
	{
		if (map->map[0][i] == '1' && map->map[map->map_height - 1][i] == '1')
			i++;
		else
			return (-1);
	}
	if (i != map->map_width)
		return (-1);
	i = 0;
	while (map->map[i])
	{
		if (map->map[i][0] == '1' && map->map[i][map->map_width - 1] == '1')
			i++;
		else
			return (-1);
	}
	if (i != map->map_height)
		return (-1);
	return (1);
}

int	check_char(t_map *map, char a, int symb, t_game *game)
{
	game->i = 0;
	while (map->map[game->i])
	{
		game->j = -1;
		while (map->map[game->i][++game->j] != '\0')
		{
			if (map->map[game->i][game->j] == a)
				symb++;
			if (a == 'P' && map->map[game->i][game->j] == a)
			{
				game->coord.y = game->i;
				game->coord.x = game->j;
			}
		}
		game->i++;
	}
	if (symb == 1 && a != 'C')
		return (1);
	if (symb > 0 && a == 'C')
	{
		map->coin = symb;
		return (1);
	}
	return (-1);
}

int	check_valid_char(t_map *map, char *symb, int l)
{
	int		i;
	char	*str;

	i = 0;
	str = map->map[i];
	while (str)
	{
		map->fd = 0;
		while (str[map->fd] != '\0')
		{
			l = 0;
			while (symb[l] && str[map->fd] != symb[l])
			{
				l++;
				if (symb[l] == '\0')
					return (-1);
			}
			map->fd++;
		}
		i++;
		str = map->map[i];
	}
	return (1);
}
