# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 13:51:23 by dnikifor          #+#    #+#              #
#    Updated: 2023/07/19 13:59:59 by dnikifor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_cat.c

OBJS = $(SRCS:.c=.o)

EXEC = ft_cat

all: $(EXEC)

$(EXEC): $(OBJS)
	cc $(CFLAGS) -o $@ $^

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
