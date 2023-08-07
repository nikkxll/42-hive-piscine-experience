/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:34:25 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/20 21:19:41 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int	ft_strlen(char *str);

int	print_error(char *message);

int	numb_check(char *str, int sign, int i, int num);

int	ft_atoi(char *str);

int	ft_strcmp(char *s1, char *s2);

int	read_whole_file(int fd, char *buffer, int buffer_size)
{
	int	total_bytes_read;
	int	bytes_read;

	total_bytes_read = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer + total_bytes_read,
				buffer_size - total_bytes_read);
		total_bytes_read += bytes_read;
	}
	return (total_bytes_read);
}

int	write_tail(int out, char *buffer, int buffer_size, int num_bytes)
{
	int	bytes_to_write;

	if (num_bytes > buffer_size)
		bytes_to_write = buffer_size;
	else
		bytes_to_write = num_bytes;
	if (write(out, buffer + buffer_size - bytes_to_write,
			bytes_to_write) == -1)
	{
		print_error(strerror(errno));
		return (1);
	}
	return (0);
}

int	ft_tail(int fd, int num_bytes)
{
	char	buffer[BUFFER_SIZE];
	int		total_bytes_read;
	int		bytes_to_read;

	total_bytes_read = read_whole_file(fd, buffer, BUFFER_SIZE);
	while (total_bytes_read > 0)
	{
		if (total_bytes_read < num_bytes)
			bytes_to_read = total_bytes_read;
		else
			bytes_to_read = num_bytes;
		if (write_tail(STDOUT_FILENO, buffer,
				total_bytes_read, bytes_to_read) == 1)
		{
			return (1);
		}
		num_bytes -= bytes_to_read;
		total_bytes_read -= bytes_to_read;
		if (num_bytes == 0)
			break ;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	result;
	int	num_bytes;
	int	fd;

	if (argc != 4)
		return (print_error("Usage: ./ft_tail -c num_bytes filename\n"));
	if (ft_strcmp(argv[1], "-c") != 0)
		return (print_error("Invalid option. Only -c is supported.\n"));
	num_bytes = ft_atoi(argv[2]);
	if (num_bytes <= 0)
		return (print_error("Invalid number of bytes.\n"));
	fd = open(argv[3], O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno));
		return (1);
	}
	result = ft_tail(fd, num_bytes);
	if (close(fd) == -1)
		return (1);
	return (result);
}
