/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_sequel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:06:46 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/19 12:10:45 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb < 0)
		return (0);
	i = 1;
	while (i * i <= (unsigned int)nb)
	{
		if (i * i == (unsigned int)nb)
			return (i);
		i++;
	}
	return (0);
}

int	flag_change(int flag, int *x)
{
	if (flag == 1)
		*x = *x - 1;
	flag = 0;
	return (flag);
}

void	square_expand(t_SubsquaresInfo *f, int *y, int *x, int *flag)
{
	f->size_y++;
	f->size_x++;
	*y = f->tmp_y;
	*x = f->tmp_x;
	*flag = 1;
}

void	number_fill(t_Grid *grid)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	num = 0;
	while (i < grid->row - 1)
	{
		j = 0;
		while (j < grid->column - 1)
		{
			num = subsquares_check(grid, i, j - 1, 0);
			grid->result_map[i][j] = num;
			j++;
		}
		i++;
	}
}

int	max_number(t_Grid *grid, int largest)
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
			if (grid->result_map[i][j] > largest)
				largest = grid->result_map[i][j];
			j++;
		}
		i++;
	}
	return (largest);
}
