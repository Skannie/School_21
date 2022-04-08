/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kannie <kannie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:24:42 by kannie            #+#    #+#             */
/*   Updated: 2022/01/12 20:36:46 by kannie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *info, ...);
int				format_read(va_list a, const char *info, int i);
int				write_char(char c);
int				write_str(char *s);
int				write_dig(va_list a);
int				write_u(va_list a);
int				write_low_x(unsigned int n);
int				write_upper_x(unsigned int n);
int				write_pointer(unsigned long int n);
int				w_p(unsigned long int n);
size_t			ft_strlen(const char *str);
int				vstepen_it(int a);
char			*podschet_it_u(long long zadan, int sum, char *fd);
char			*ft_strdup(const char *s1);
char			*podschet_it(long long zadan, int sum, char *fd);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);

#endif