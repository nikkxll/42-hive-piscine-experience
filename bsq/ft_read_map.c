/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:35:30 by asohrabi          #+#    #+#             */
/*   Updated: 2023/07/18 14:06:33 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
char	*ft_strndup(char *src, int n);
int		ft_strnlen(char *str, int max_len);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

typedef struct s_map
{
	int		x;
	int		y;
	char	c;
	char    **map;
}		t_map;

typedef struct Grid
{ 
    int 	row; // x
    int 	column; // y
	char	c;
	int		line_num;
	char	empty;
    char 	obs; // o
    char 	filler;//f
    char	**map;
    int		**resultMap; //malloc the same size
} 			t_Grid;
/*
typedef struct s_fl
{
	int		l_num;
	char	e_char;
	char	o_char;
	char	f_char;
}			t_fl;
*/
int	char_count(int fd)
{
	char	buffer[5000];
	int		bytes_read;
	int		i;

	bytes_read = read(fd, buffer, 5000);
	i = 0;
	while (i < bytes_read)
	{
		i++;
	}
//	printf("char count: %d\n", i);
	return (i);
}

void	ft_first_line(char *buf)
{
	char	*line_start;
	char	*line_end;
	char	*fl_str;
	t_Grid	*Grid;
	int		len;
	char	num_buffer[5000];

	Grid = (t_Grid*){0};
	line_start = buf;
	line_end = ft_strchr(buf, '\n');
	if (line_end != NULL)
	{
		*line_end = '\0';
		fl_str = ft_strndup(line_start, line_end - line_start);
		len = ft_strlen(fl_str);
		if (len < 4)
		{
			ft_putstr("map error\n");
			free(fl_str);
			return ;
		}
		else
		{
			len = ft_strnlen(fl_str, line_end - line_start);
			Grid->filler = fl_str[len - 1];
			Grid->obs = fl_str[len - 2];
			Grid->empty = fl_str[len - 3];
			ft_strncpy(num_buffer, fl_str, len - 3);
			num_buffer[len - 3] = '\0';
			Grid->line_num = ft_atoi(num_buffer);
		}
		free(fl_str);
	}
}

int	ft_count_lines(int fd, char *path)
{
	char	buf[5000];
	int		line_count;
	int		bytes_read;
	int		i;

	i = 0;
	line_count = 0;
	close(fd);
	fd = open(path, O_RDONLY);
	bytes_read = read(fd, buf, 5000);
//	printf("count lines byte read: %d\n", bytes_read);
	while (i < bytes_read)
	{
		if (buf[i] == '\n')
			line_count++;
		i++;
	}
	return (line_count - 1);
}


void parse_line(int fd, char *path, t_map **map)
{
    int current_index = 0;
    char ch;
    int x = 0; // Initialize x to 0 to count the number of characters per line
    int y = 0; // Initialize y to 0 to count the number of lines
	int a;
	t_Grid *Grid;

//	Grid = (t_Grid *)malloc(sizeof(t_Grid) * 2);
    // Allocate memory for the map dynamically
    *map = (t_map *)malloc(sizeof(t_map) * 5000); // Assuming a maximum of 5000 map cells per line
    if (*map == NULL)
    {
        ft_putstr("Memory allocation error.\n");
        exit(1);
    }

    // Read the entire map data into buf character by character
    int bytes_read;
	close(fd);
	fd = open(path, O_RDONLY);
	a = char_count(fd);
	close(fd);
	fd = open(path, O_RDONLY);
    while ((bytes_read = read(fd, &ch, 1)) > 0)
    {
        if (ch == '\n')
        {
            // Found a newline character, update the line count and reset x
            x++;
            y = 0;
            continue; // Skip printing the newline character
        }
        else if (ch != '\0')
        {
            // Check if we have reached the first line of the map
            if (x > 0)
            {
                // Store the map cell information in the map array
                (*map)[current_index].x = x - 1;
                (*map)[current_index].y = y;
                (*map)[current_index].c = ch;
                current_index++;
                y++;
            }
        }
    }
	y = a / x;
	Grid->map = (char **)malloc(x * sizeof(char *));
	for (int i = 0; i < x - 1; i++) {
    	Grid->map[i] = (char *)malloc((y + 1) * sizeof(char));
	}
	Grid->row = x - 1 + 2;
	Grid->column = y + 2;
    int i = 0;
    int j = 0;
    while (i < (x - 1))
    {
        while (j < y)
        {
            ft_putchar((*map)[i * y + j].c);
            j++;
        }
        ft_putchar('\n'); // Add a newline after printing each line
        j = 0; // Reset j for the next line
        i++;   // Move to the next line
    }
	// Initialize the Grid array
	i = 0;
	j = 0;
	for (int i = 0; i < x; i++) {
    	for (int j = 0; j < y; j++) {
        Grid->map[i][j] = (*map)[i * y + j].c;
    	}
    Grid->map[i][y] = '\0'; // Null-terminate each row
	}
}
//	free(map);

t_map	*ft_read_map(int fd, char *path, char *buf)
{
	t_map	*map;
	int		lines_count;

	lines_count = ft_count_lines(fd, path);
	printf("lines: %d\n", lines_count);
	if (lines_count <= 0)
	{
		ft_putstr("map error\n");
		close(fd);
		return (0);
	}
	map = (t_map *)malloc(lines_count * sizeof(t_map));
	if (map == 0)
	{
		ft_putstr("map error\n");
		close(fd);
		free(map);
		return (0);
	}
	parse_line(fd, path, &map);
	return (map);
}
