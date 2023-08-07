/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:11:47 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/19 12:22:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	subsquares_check(t_Grid *grid, int y, int x, int flag)
{
	t_SubsquaresInfo	f;
	int					res;

	f.size_y = y + 1;
	f.size_x = x + 2;
	f.tmp_y = y;
	f.tmp_x = x + 1;
	while (x++ < f.size_x)
	{
		y = f.tmp_y;
		flag = flag_change(flag, &x);
		res = (f.size_x - f.tmp_x - 1) * (f.size_x - f.tmp_x - 1);
		while (y < f.size_y)
		{
			if (grid->map[y][x] == grid->obs)
				return ((f.size_x - f.tmp_x - 1) * (f.size_x - f.tmp_x - 1));
			if ((f.tmp_y == y - ft_sqrt(res)) && (f.tmp_x == x - ft_sqrt(res)))
			{
				square_expand(&f, &y, &x, &flag);
				break ;
			}
			y++;
		}
	}
	return (0);
}

void	array_with_only_max(t_Grid *grid, int largest)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < grid->row - 1)
	{
		j = 1;
		while (j < grid->column - 1)
		{
			if (grid->result_map[i][j] == largest)
			{
				j++;
				continue ;
			}
			else
			{
				grid->result_map[i][j] = 0;
				j++;
			}
		}
		i++;
	}
}

void	square_fill(t_Grid *grid, int i, int j, int num)
{
	int	tmp_i;
	int	tmp_j;

	while (i < grid->row - 1)
	{
		j = 1;
		while (j < grid->column - 1)
		{
			if (grid->result_map[i][j] != 0)
			{
				num = grid->result_map[i][j];
				tmp_i = i;
				tmp_j = j;
				while (i++ < (tmp_i + ft_sqrt(num)))
				{
					j = tmp_j;
					while (j++ < (tmp_j + ft_sqrt(num)))
						grid->map[i - 1][j - 1] = grid->filler;
				}
				return ;
			}
			j++;
		}
		i++;
	}
}

void	free_memory(t_Grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->row)
	{
		free(grid->map[i]);
		i++;
	}
	free(grid->map);
	i = 0;
	while (i < grid->row)
	{
		free(grid->result_map[i]);
		i++;
	}
	free(grid->result_map);
}

void	ft_core(t_Grid *grid)
{
	int	max_num;
	int	i;
	int	j;

	max_num = 0;
	i = 1;
	j = 1;
	number_fill(grid);
	max_num = max_number(grid, max_num);
	array_with_only_max(grid, max_num);
	square_fill(grid, 1, 1, 0);
	while (i < grid->row - 1)
	{
		j = 1;
		while (j < grid->column - 1)
		{
			ft_putchar(grid->map[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	free_memory(grid);
}
/*
int main()
{
    int row = 11;
    int column = 29;

    t_Grid grid;
    grid.row = row;
    grid.column = column;
    grid.obs = 'o';
    grid.filler = 'x';

    // Allocate memory for map
    grid.map = (char**)malloc(row * sizeof(char*));
    for (int i = 0; i < row; i++) {
        grid.map[i] = (char*)malloc(column * sizeof(char));
    }

    // Allocate memory for result_map
    grid.result_map = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        grid.result_map[i] = (int*)malloc(column * sizeof(int));
    }

    // Initialize map and result_map
    char initialMap[11][29] = {
        { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' },
        { 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o' },
        { 'o', '.', 'o', '.', '.', 'o', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', 'o' },
        { 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', 'o' },
        { 'o', '.', 'o', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', 'o' },
        { 'o', '.', '.', '.', '.', 'o', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o' },
        { 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', 'o' },
        { 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o' },
        { 'o', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', 'o' },
        { 'o', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'o' },
        { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' }
    };


    // Copy initialMap to grid.map
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            grid.map[i][j] = initialMap[i][j];
        }
    }

    ft_core(&grid);

    return 0;
}
*/
