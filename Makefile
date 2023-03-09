# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 13:03:38 by hguillau          #+#    #+#              #
#    Updated: 2023/02/27 14:17:23 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=		main.c						\
					includes/so_long_utils.c	\
					includes/so_long_utils2.c	\
					includes/get_map.c			\
					gnl/get_next_line.c			\
					gnl/get_next_line_utils.c	\
					includes/secu.c				\
					includes/secu2.c			\
					includes/recup_d.c			\
					includes/movement.c			\
					printf/ft_printf.c			\
					printf/ft_printf_func.c		\
					printf/ft_printf_func2.c	\
					includes/bonus.c			\
					includes/ennemi.c			\

LIBFT		= 		libft/libft.a

OBJS    	=		${SRCS:.c=.o}

NAME    	=		so_long

CC      	=		gcc

RM      	=		rm -f

CFLAGS  	=		-Wall -Wextra -Werror -Imlx #-g -fsanitize=address

all:				LIBFT_M ${NAME}

LIBFT_M		:		
					make -C libft/ all

${NAME}:			${OBJS}
					${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} ${LIBFT}

clean:
					${RM} ${OBJS}

fclean: 			clean
					${RM} ${NAME}

re:     			fclean all

bonus:				all

.PHONY: 			all clean fclean re
