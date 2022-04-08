/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:25:10 by kannie            #+#    #+#             */
/*   Updated: 2022/02/12 14:23:55 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *info, ...)
{
	va_list			a;
	int				number;
	int				i;

	va_start(a, info);
	i = 0;
	number = 0;
	while (info[i] != '\0')
	{
		if (info[i] == '%')
		{
			if (info[i + 1] > 0 && info[i + 1] < 10)
			{
				
			}
			number += format_read(a, info, i + 1);
			i++;
		}
		else
			number += write_char(info[i]);
		i++;
	}
	va_end(a);
	return (number);
}

int	format_read(va_list a, const char *info, int i)
{
	int	number;

	number = 0;
	if (info[i] == 'i' || info[i] == 'd')
		number += write_dig (a);
	else if (info[i] == 'c')
		number += write_char (va_arg(a, int));
	else if (info[i] == '%')
		number += write_char('%');
	else if (info[i] == 's')
		number += write_str (va_arg(a, char *));
	else if (info[i] == 'u')
		number += write_u (a);
	else if (info[i] == 'p')
		number += write_pointer (va_arg(a, unsigned long int));
	else if (info[i] == 'x')
		number += write_low_x (va_arg(a, int));
	else if (info[i] == 'X')
		number += write_upper_x (va_arg(a, int));
	return (number);
}

int	main(void)
{
	ft_printf("%3.5f", 12345.123);
	printf("\n%5s", "12123123412345");
}
