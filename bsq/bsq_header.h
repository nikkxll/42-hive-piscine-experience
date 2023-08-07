/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:35:07 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/19 12:04:40 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct Grid
{
	int		row;
	int		column;
    char    c;
    int     line_num;
    char    empty;
	char	obs;
	char	filler;
	char	**map;
	int		**result_map;
}			t_Grid;

typedef struct SubsquatesInfo
{
	int	size_y;
	int	size_x;
	int	tmp_y;
	int	tmp_x;
}		t_SubsquaresInfo;

void	ft_putchar(char c);
int		ft_sqrt(int nb);
int		subsquares_check(t_Grid *grid, int y, int x, int flag);
void	number_fill(t_Grid *grid);
int		max_number(t_Grid *grid, int largest);
void	array_with_only_max(t_Grid *grid, int largest);
void	square_fill(t_Grid *grid, int i, int j, int num);
void	ft_core(t_Grid *grid);
int		flag_change(int flag, int *x);
void	square_expand(t_SubsquaresInfo *f, int *y, int *x, int *flag);
void	free_memory(t_Grid *grid);

#endif
