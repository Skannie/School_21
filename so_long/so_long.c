/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:22:55 by kannie            #+#    #+#             */
/*   Updated: 2022/04/05 17:02:05 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	if (argc == 2)
	{
		i = check_ber(argv[1]);
		if (i != 1)
			print_exit("Wrong name map!");
		game.moves = 0;
		game.coord.x = 0;
		game.coord.y = 0;
		initial_check_map(&game, argv[1]);
		game.mlx.mlx = mlx_init();
		initial_map(&game);
		mlx_hook(game.mlx.mlx_win, 2, 0L, key_hook, &game);
		mlx_hook(game.mlx.mlx_win, 17, 1L << 0, ex_exit, &game);
		mlx_loop(game.mlx.mlx);
		return (i);
	}
	else
	{
		print_exit(NULL);
		return (0);
	}
}
