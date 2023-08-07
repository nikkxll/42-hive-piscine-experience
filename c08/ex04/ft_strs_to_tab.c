/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:20:58 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/12 11:05:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*ptr;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == 0)
	{
		return (0);
	}
	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					index;
	struct s_stock_str	*array;

	array = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (array == 0)
		return (0);
	index = 0;
	while (index < ac)
	{
		array[index].size = ft_strlen(av[index]);
		array[index].str = av[index];
		array[index].copy = ft_strdup(av[index]);
		index++;
	}
	array[index] = (struct s_stock_str){0, 0, 0};
	return (array);
}
/*
int                    main(int argc, char **argv)
{
    int                    index;
    struct s_stock_str    *structs;

    structs = ft_strs_to_tab(argc, argv);
    index = 0;
    while (index < argc)
    {
        printf("%d\n", index);
        printf("\t| original : $%s$ @ %p\n",
	     structs[index].str, structs[index].str);
        printf("\t|   copied : $%s$ @ %p\n",
         structs[index].copy, structs[index].copy);
        printf("\t|     size : %d\n", structs[index].size);
        index++;
    }
}
*/
