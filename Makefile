# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 01:05:33 by robindehouc       #+#    #+#              #
#    Updated: 2022/03/16 11:23:22 by robindehouc      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

srcs = srcs/main.c srcs/instructions.c srcs/sort_radix.c srcs/sorter.c \
	   utilitary/t_list.c utilitary/utils.c utilitary/args.c utilitary/indexor.c 

OBJS = ${srcs:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re