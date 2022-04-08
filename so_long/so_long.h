/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:57:29 by kannie            #+#    #+#             */
/*   Updated: 2022/04/05 16:50:08 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"
# include <stdio.h>

# define CEL_SIZE 16

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
}	t_imgs;

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
}	t_mlx;

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_map
{
	char	**map;
	char	*line;
	char	*buf;
	int		fd;
	int		map_width;
	int		map_height;
	int		coin;
}	t_map;

typedef struct s_game
{
	t_mlx	mlx;
	t_map	map;
	t_coord	coord;
	t_imgs	imgs;
	int		moves;
	int		i;
	int		j;
}	t_game;

void	move(t_game *game, int x, int y);
void	print_move(t_game *game);
void	initial_map(t_game *game);
void	img_to_maps(t_game *game);
void	img_to_maps_1(t_game *game, char a);
int		size_map(t_map *map, char *name_map);
int		record_map(t_map *map, char *name_map);
int		check_wall(t_map *map);
int		check_map(t_map *map, t_game *game);
int		check_ber(char *str);
int		get_imgs(t_game *game);
int		ft_strstr(char *str1, char *str2);
int		initial_check_map(t_game *game, char *name_map);
int		check_wall(t_map *map);
int		check_char(t_map *map, char a, int symb, t_game *game);
int		check_valid_char(t_map *map, char *str, int symb);
int		key_hook(int keycode, t_game *game);
void	print_exit(char *str);
int		ex_exit(void *param);

#endif