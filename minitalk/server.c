/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:51:25 by kannie            #+#    #+#             */
/*   Updated: 2022/03/05 19:43:35 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = (unsigned int)(n * -1);
	}
	else
	{
		i = (unsigned int)n;
		if (i > 9)
			ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd((char)(i % 10 + '0'), fd);
	}
}

static void	sig_receive(int sig)
{
	static char	a = 0;
	static int	i = 7;
	int			num;

	num = 0;
	if (sig == SIGUSR1)
		a |= (1 << i);
	if (sig == SIGUSR2)
		a &= ~(1 << i);
	i--;
	if (i < 0)
	{
		i = 7;
		write(1, &a, 1);
		num++;
		if (a == 0)
			write(1, "\n", 1);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd (pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_receive);
	signal(SIGUSR2, sig_receive);
	while (1)
		pause();
}
