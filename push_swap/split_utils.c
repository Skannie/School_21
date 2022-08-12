/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:30:39 by kannie            #+#    #+#             */
/*   Updated: 2022/06/29 16:24:26 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spl_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i > -1)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

t_stack	*split_stk(char **argv, t_stack *new, t_stack *res, int i)
{
	int		j;
	char	**spl;

	while (argv[++i])
	{
		j = 0;
		spl = ft_split(argv[i], ' ');
		while (spl[j])
		{
			new = (t_stack *)malloc(sizeof(t_stack));
			if (!new)
				exit(0);
			new->data = ft_atoi(spl[j]);
			new->next = NULL;
			if (!res)
				res = new;
			else
				go_last(res)->next = new;
			j++;
		}
		spl_free(*(&spl));
	}
	return (res);
}
