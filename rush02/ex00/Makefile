# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 12:21:21 by dnikifor          #+#    #+#              #
#    Updated: 2023/07/16 17:54:28 by rboudwin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_putnbr.c \
		write.c \
		ft_atoi.c \
		main.c \
		parse_dictionary.c \
		text_converter.c \
		ft_putnbr_the_sequel.c \
		parse_dictionary_the_sequel.c

OBJS = $(SRCS:.c=.o)

EXEC = rush-02

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

