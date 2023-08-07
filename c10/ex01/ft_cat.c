/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:34:10 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/20 21:40:25 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 30720

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str != '\0')
	{
	counter++;
	str++;
	}
	return (counter);
}

int	error_file(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	return (1);
}

int	error_argc(void)
{
	write(2, "Usage: ft_cat <filename>\n", 25);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		file_descriptor;
	ssize_t	read_bytes;
	char	buffer[MAX_SIZE];

	if (argc != 2)
		return (error_argc());
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
		return (error_file());
	read_bytes = read(file_descriptor, buffer, MAX_SIZE);
	while (read_bytes > 0)
	{
		write(1, buffer, read_bytes);
		read_bytes = read(file_descriptor, buffer, MAX_SIZE);
	}
	if (close(file_descriptor) == -1)
		return (error_file());
	return (0);
}
