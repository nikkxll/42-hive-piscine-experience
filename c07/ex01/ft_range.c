/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:45:12 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/10 20:09:50 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	*res;

	if (min >= max)
	{
		return (0);
	}
	ptr = malloc((max - min) * sizeof(int));
	if (ptr == 0)
	{
		return (0);
	}	
	res = ptr;
	while (min < max)
	{
		*ptr = min;
		ptr++;
		min++;
	}
	return (res);
}

/*
int main() {
  int min = 7;
  int max = 17;
  int *arr;

  arr = ft_range(min, max);
  if (arr == 0) {
    printf("Memory allocation failed");
    return 0;
  }

  int *current = arr;
  while (current < arr + (max - min))
  {
      printf("Final copied string: %i\n", *current);
      current++;
  }

  return 0;
}
*/
