# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 13:51:23 by dnikifor          #+#    #+#              #
#    Updated: 2023/07/20 18:38:58 by dnikifor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_hexdump.c

OBJS = $(SRCS:.c=.o)

EXEC = ft_hexdump

all: $(EXEC)

$(EXEC): $(OBJS)
	cc $(CFLAGS)  -o $@ $^

%.o: %.c ex02.h
	cc $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
