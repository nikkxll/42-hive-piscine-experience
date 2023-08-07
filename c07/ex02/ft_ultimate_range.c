/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:02:26 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/11 10:50:12 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	else
	{
		*range = (int *) malloc ((max - min) * sizeof (int));
		if (*range == 0)
			return (-1);
		i = min;
		j = 0;
		while (i < max)
		{
			*(*range + j) = i;
			j++;
			i++;
		}
		return (max - min);
	}
}
/*
int main ()
{
	int	i = 0;
	int	*r;
	int max = 15;
	int min = 1;
	
	ft_ultimate_range (&r, min, max);
	while (i < (max - min))
	{
		printf ("%d\n", *(r+i));
		i++;
	}
	return (0);
}
*/
