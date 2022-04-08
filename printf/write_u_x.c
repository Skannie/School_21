/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:37:04 by kannie            #+#    #+#             */
/*   Updated: 2022/01/12 20:35:15 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_u(va_list a)
{
	int		number;
	char	*str;

	number = 0;
	str = ft_uitoa(va_arg (a, unsigned int));
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

int	write_low_x(unsigned int n)
{
	int			i;
	char		*str;

	i = 1;
	str = "0123456789abcdef";
	if (n > 15)
	{
		i += write_low_x (n / 16);
		write_low_x (n % 16);
	}
	else
		write (1, &str[n], 1);
	return (i);
}

int	write_upper_x(unsigned int n)
{
	int			i;
	char		*str;

	i = 1;
	str = "0123456789ABCDEF";
	if (n > 15)
	{
		i += write_upper_x (n / 16);
		write_upper_x (n % 16);
	}
	else
		write (1, &str[n], 1);
	return (i);
}

char	*podschet_it_u(long long zadan, int sum, char *fd)
{
	int				i;
	long long		l;

	i = 0;
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
