/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:02:54 by asohrabi          #+#    #+#             */
/*   Updated: 2023/07/19 18:03:45 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	empty;
    char 	obs; // o
    char 	filler;//f
    char	**map;
    int		**resultMap; //malloc the same size
} 			t_Grid;

typedef struct s_fl
{
	int		l_num;
	char	e_char;
	char	o_char;
	char	f_char;
}			t_fl;

void    parse_line(int fd, char *path, t_map **map);

void	ft_first_line(char *buf);

void	ft_core(t_Grid *grid);

void    ft_map(int fd, char *path, char *buf, t_map **map)
{
    int     i;
    int     j;
    t_Grid  *Grid;

    i = 0;
    j = 0;
    parse_line(fd, path, map);
    ft_first_line(buf);
    ft_core(Grid);
}
