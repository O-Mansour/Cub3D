# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alagmiri <alagmiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 10:00:38 by alagmiri          #+#    #+#              #
#    Updated: 2023/10/03 19:27:34 by alagmiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	parsing/check_error.c parsing/check_map.c parsing/data.c parsing/rgb.c parsing/textures.c\
			raycasting/draw.c raycasting/clicks.c raycasting/dda.c raycasting/utils.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

M_MAND	=	main.c

M_BONUS	=	main_bonus.c

O_MAND	=	${M_MAND:.c=.o}

O_BONUS	=	${M_BONUS:.c=.o}

OBJS	=	${SRCS:.c=.o}

NAME	=	cub3D

NAME_B	=	cub3D_bonus

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-lXext -lX11 -lm -lz -lmlx_Linux

MLXL	=	 ../minilibx-linux/libmlx_Linux.a

LIBFT	=	./libft/libft.a

all		:	mlx ${NAME}

${NAME}	:	${LIBFT} ${OBJS} ${O_MAND}
	${CC} ${CFLAGS} ${OBJS} ${O_MAND} ${LIBFT} ${MLXL} ${LFLAGS} -o ${NAME}

bonus	:	mlx ${NAME_B}

${NAME_B}	:	${LIBFT} ${OBJS} ${O_BONUS}
	${CC} ${CFLAGS} ${OBJS} ${O_BONUS} ${LIBFT} ${MLXL} ${LFLAGS} -o ${NAME_B}

${LIBFT} :
	make -C libft

mlx	:
	make -C ../minilibx-linux

clean :
	make clean -C libft
	rm -f ${OBJS} ${O_MAND} ${O_BONUS}

fclean : clean
	rm -f ${NAME} ${NAME_B} ${LIBFT}

re : fclean all
