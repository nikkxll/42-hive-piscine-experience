#!/bin/sh -e
gcc -c -Wall -Werror -Wextra *.c
ar -rcs libft.a *.o
rm -f *.o
