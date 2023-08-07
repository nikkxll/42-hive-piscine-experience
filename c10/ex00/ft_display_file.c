/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:09 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/20 21:31:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 30720

int	ft_putstr_e(char *str)
{
	char	*arrow;

	arrow = str;
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
	return (1);
}

int	ft_putstr(char *str)
{
	char	*arrow;

	arrow = str;
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		file_id;
	char	buffer [MAX_SIZE];
	char	*filename;
	int		bytes_read;

	if (argc > 2)
		return (ft_putstr_e("Too many arguments.\n"));
	else if (argc < 2)
		return (ft_putstr_e("File name missing.\n"));
	filename = argv[1];
	file_id = open(filename, O_RDONLY);
	if (file_id == -1)
		return (ft_putstr_e("Cannot read file.\n"));
	bytes_read = read(file_id, buffer, MAX_SIZE);
	if (bytes_read == -1)
		return (ft_putstr_e("Cannot read file.\n"));
	buffer[bytes_read] = '\0';
	ft_putstr(buffer);
	close(file_id);
	if (close(file_id) == -1)
		return (0);
	return (0);
}
