/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:51:30 by kannie            #+#    #+#             */
/*   Updated: 2022/03/05 19:43:39 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static void	sendchr(pid_t pid, char a)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (a & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep (100);
	}
}

static void	sendstr(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		sendchr(pid, str[i]);
		i++;
	}
	sendchr(pid, 0);
}

static	int	ft_atoi(const char *str)
{
	int	i;
	int	degr;

	degr = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		degr = degr * 10 + (str[i++] - '0');
	return (degr);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc == 3)
	{
		str = argv[2];
		pid = ft_atoi(argv[1]);
		sendstr(pid, str);
	}
	else
		return (1);
}
