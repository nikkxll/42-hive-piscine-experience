# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 17:15:37 by dnikifor          #+#    #+#              #
#    Updated: 2023/07/13 17:47:05 by dnikifor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FUNCS = srcs/ft_putchar.c \
			srcs/ft_swap.c \
			srcs/ft_putstr.c \
			srcs/ft_strlen.c \
			srcs/ft_strcmp.c

INCS = includes

OBJ = ${FUNCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc ${CFLAGS} -c $< -o $@ -I${INCS}

all: ${NAME}

${NAME}: ${OBJ}	
	ar -rsc ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
