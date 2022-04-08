# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kannie <kannie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 18:41:35 by kannie            #+#    #+#              #
#    Updated: 2022/03/26 17:57:29 by kannie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

HEADER			=	ft_printf.h

SRCS		=	ft_printf.c ft_printf_utils.c write_dig.c \
				write_pointer.c write_s_char.c write_u_x.c

OBGS		=	${SRCS:%.c=%.o}

RM			=	rm -f


all:		${NAME}

${NAME}:	${OBGS} ${HEADER}
			ar rcs ${NAME} $?
			ranlib ${NAME}

%.o:		%.c	${HEADER}
			${CC} ${FLAGS} -c $< -o $@

clean:		
			${RM} ${OBGS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re