# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kannie <kannie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 20:38:08 by kannie            #+#    #+#              #
#    Updated: 2022/03/26 17:56:37 by kannie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	push_swap.c push_swap_ps.c\
				push_swap_r.c push_swap_rr.c\
				push_swap_utils.c\
				sort.c sort1.c sort2.c\
				sort3.c

HEADER		=	push_swap.h

OBJS		=	${SRCS:%.c=%.o}

CC			=	gcc

FLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

all:		$(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(CC) $(OBJS) -o $(NAME)

clean:
			${RM} $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re