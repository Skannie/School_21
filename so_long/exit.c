/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:40:40 by kannie            #+#    #+#             */
/*   Updated: 2022/04/05 16:57:02 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ex_exit(void *param)
{
	(void) param;
	exit(0);
	return (0);
}

void	print_exit(char *str)
{
	write(1, "Error\n", 6);
	if (str)
	{
		ft_putstr_fd(str, 1);
		write(1, "\n", 1);
	}
	exit(1);
}
