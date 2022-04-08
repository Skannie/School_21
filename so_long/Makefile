NAME		=	so_long

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

HEADER		=	mlx.h

LIBFT		=	libft/libft.a

SRCS		=	maps_read.c check_map.c so_long.c \
				maps_init.c exit.c initial_game.c\
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c

OBJS		=	${SRCS:%.c=%.o}

RM			=	rm -f

MLX_FLAGS	=	-L ./mlx -lmlx -framework OpenGL -framework AppKit

${NAME}:	$(OBJS)
			make -C ./mlx
			make -C ./libft
			$(CC) $(OBJS) ${LIBFT} ${MLX_FLAGS} -o $(NAME)

%.o:		%.c
			$(CC) ${FLAGS} -Imlx -c $< -o $@
			
all:		${NAME}

clean:		
			${RM} ${OBJS}
			make clean -C ./libft

fclean:		clean
			${RM} ${NAME}
			make fclean -C ./libft
			make clean -C ./mlx

re:			fclean all

.PHONY: all clean fclean re