/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:08:12 by kannie            #+#    #+#             */
/*   Updated: 2022/04/05 12:32:36 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_imgs(t_game *game)
{
	int	a;

	a = 50;
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx.mlx, "./picture/wall.xpm",
			&a, &a);
	if (!game->imgs.wall)
		print_exit("Picture reading problem!");
	game->imgs.floor = mlx_xpm_file_to_image(game->mlx.mlx,
			"./picture/floor.xpm", &a, &a);
	if (!game->imgs.floor)
		print_exit("Picture reading problem!");
	game->imgs.player = mlx_xpm_file_to_image((void *)game->mlx.mlx,
			"./picture/snake.xpm", &a, &a);
	if (!game->imgs.player)
		print_exit("Picture reading problem!");
	game->imgs.coin = mlx_xpm_file_to_image(game->mlx.mlx,
			"./picture/apple.xpm", &a, &a);
	if (!game->imgs.coin)
		print_exit("Picture reading problem!");
	game->imgs.exit = mlx_xpm_file_to_image(game->mlx.mlx, "./picture/exit.xpm",
			&a, &a);
	if (!game->imgs.coin)
		print_exit("Picture reading problem!");
	return (1);
}

void	img_to_maps_1(t_game *game, char a)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->imgs.floor, (50 * game->j), (50 * game->i));
	if (a == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->imgs.player, (50 * game->j), (50 * game->i));
	}
	if (a == 'C')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->imgs.coin, (50 * game->j + 15),
			(50 * game->i + 15));
	}
	if (a == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
			game->imgs.exit, (50 * game->j), (50 * game->i));
	}
}

void	img_to_maps(t_game *game)
{
	game->i = 0;
	while (game->map.map[game->i])
	{
		game->j = 0;
		while (game->map.map[game->i][game->j] != '\0')
		{
			if (game->map.map[game->i][game->j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
					game->imgs.wall, (50 * game->j), (50 * game->i));
			if (game->map.map[game->i][game->j] == '0')
				img_to_maps_1(game, '0');
			if (game->map.map[game->i][game->j] == 'P')
				img_to_maps_1(game, 'P');
			if (game->map.map[game->i][game->j] == 'C')
				img_to_maps_1(game, 'C');
			if (game->map.map[game->i][game->j] == 'E')
				img_to_maps_1(game, 'E');
			game->j++;
		}
		game->i++;
	}
}
