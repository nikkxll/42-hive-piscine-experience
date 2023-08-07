/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:08:16 by asohrabi          #+#    #+#             */
/*   Updated: 2023/07/19 10:10:05 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str);

typedef struct s_map
{
	int		x;
	int		y;
	char	c;
}		t_map;

t_map	*ft_read_map(int fd, char *path, char *buf);

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		bytes_read;
	char	buf[5000];

	i = 1;
	if (argc == 1)
    {
        // Handle reading from standard input (stdin)
        bytes_read = read(0, buf, sizeof(buf) - 1);
        buf[bytes_read] = '\0';
        // For example: ft_read_stdin(buf);
        // maybe I need to define another similar function in the case of stdin
    }
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr("map error\n");
				exit(1);
			}
			bytes_read = read(fd, buf, sizeof(buf) - 1);
		//	printf("main byte read: %d\n", bytes_read);
			buf[bytes_read] = '\0';
			t_map *map = ft_read_map(fd, argv[i], buf);
			close(fd);
			free(map);
			i++;
		}
	}
	return (0);
}
