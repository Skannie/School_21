/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:54:47 by kannie            #+#    #+#             */
/*   Updated: 2022/01/12 20:08:28 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_pointer(unsigned long int n)
{
	int		number;

	number = 0;
	number = write_str("0x");
	number += w_p(n);
	return (number);
}

int	w_p(unsigned long int n)
{
	int		i;
	char	*str;

	i = 1;
	str = "0123456789abcdef";
	if (n > 15)
	{
		i += w_p (n / 16);
		w_p (n % 16);
	}
	else
		write (1, &str[n], 1);
	return (i);
}
