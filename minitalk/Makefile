# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kannie <kannie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 17:08:55 by kannie            #+#    #+#              #
#    Updated: 2022/03/05 19:43:14 by kannie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minitalk

RM				=	rm -f

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

NAME_SERV		=	server

SRCS_SERV		=	server.c 

OBJS_SERV		=	${SRCS_SERV:.c=.o}

NAME_CLIE		=	client

SRCS_CLIE		=	client.c

OBJS_CLIE		=	${SRCS_CLIE:.c=.o}

SRCS_MORE		= ft_atoi.c ft_putnbr_fd.c

${NAME}:		${NAME_SERV} ${NAME_CLIE}

${NAME_SERV}:	${OBJS_SERV}
				${CC} ${CFLAGS} $^ -o $@

${NAME_CLIE}:	${OBJS_CLIE}
				${CC} ${FLAGS} $^ -o $@

all:			${NAME}

clean:
				${RM} ${OBJS_SERV} ${OBJS_CLIE}

fclean:			clean
				${RM} ${NAME_SERV} ${NAME_CLIE}

re:				fclean all

.PHONY: all clean fclean re