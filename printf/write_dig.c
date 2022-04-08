/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:49:17 by kannie            #+#    #+#             */
/*   Updated: 2022/01/12 20:34:47 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_dig(va_list a)
{
	char	*str;
	int		number;

	number = 0;
	str = ft_itoa(va_arg(a, int));
	if (!str)
	{
		write (1, "(null)", 6);
		free (str);
		str = NULL;
		return (6);
	}
	number = write_str(str);
	free (str);
	str = NULL;
	return (number);
}

int	vstepen_it(int a)
{
	int			i;
	long int	step;

	i = 0;
	step = 1;
	while (a > i)
	{
		step = 10 * step;
		i++;
	}
	return (step);
}

char	*podschet_it(long long zadan, int sum, char *fd)
{
	int				i;
	long long		l;

	i = 0;
	if (fd[0] == '-')
		i = 1;
	if (zadan == 0)
	{
		fd[0] = 0 + 48;
		i++;
	}
	else
	{
		while (sum > 0)
		{
			l = (zadan / vstepen_it(sum - 1));
			fd[i] = (l % 10 + 48);
			sum--;
			i++;
		}
	}
	fd[i] = '\0';
	return (fd);
}

char	*ft_itoa(int n)
{
	long long		i;
	int				b;
	char			*str;

	i = n;
	b = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (i != 0)
	{
		i = i / 10;
		b++;
	}
	str = (char *)malloc(sizeof(char) * (b + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i = (long long)n * (-1);
		str = podschet_it(i, b, str);
	}
	else
		str = podschet_it(n, b, str);
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	i;
	int				b;
	char			*str;

	i = n;
	b = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (i != 0)
	{
		i = i / 10;
		b++;
	}
	str = (char *)malloc(sizeof(char) * (b + 1));
	if (str == NULL)
		return (NULL);
	str = podschet_it_u(n, b, str);
	return (str);
}
