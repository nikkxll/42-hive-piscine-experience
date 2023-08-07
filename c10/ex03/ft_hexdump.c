/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:14:46 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/20 18:49:19 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void	print_offset(int offset)
{
	int		i;
	char	offset_str[8];
	int		val;

	i = 6;
	offset_str[7] = '\0';
	while (i >= 0)
	{
		val = offset & 0xF;
		if (val < 10)
			offset_str[i] = '0' + val;
		else
			offset_str[i] = 'a' + val - 10;
		offset >>= 4;
		i--;
	}
	write(1, offset_str, 7);
}

void	print_hex(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i % 1 == 0)
			write(1, "  ", 2);
		if (buffer[i] >= 32 && buffer[i] <= 126)
		{
			write(1, " ", 1);
			write(1, &buffer[i], 1);
		}
		else
			write(1, "\\n", 2);
		if ((i + 1) % 16 == 0 || i == size - 1)
			write(1, "\n", 1);
		i++;
	}
}

void	ft_hexdump(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		total_bytes_read;
	int		ret;
	int		bytes_read;

	total_bytes_read = 0;
	while (1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			bytes_read = ret;
			print_offset(total_bytes_read);
			print_hex(buffer, bytes_read);
			total_bytes_read += bytes_read;
		}
		else if (ret == 0)
		{
			print_offset(total_bytes_read);
			write(1, "\n", 1);
			break ;
		}
		else
			return ;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc != 3)
		return (0);
	if (ft_strcmp(argv[1], "-c") != 0)
		return (0);
	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (0);
	ft_hexdump(fd);
	if (close(fd) == -1)
		return (0);
	return (0);
}
