/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:32:27 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/10 20:25:07 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>

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

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr;

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

int	res_length(int size, int total_length, int sep_length, char **strs)
{
	int	i;

	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			total_length += sep_length;
		}
		i++;
	}
	return (total_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		i;
	int		index;
	char	*result;

	total_length = 0;
	i = 0;
	index = 0;
	total_length = res_length(size, total_length, ft_strlen(sep), strs);
	result = (char *)malloc((total_length + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcpy(&result[index], strs[i]);
		index += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(&result[index], sep);
			index += ft_strlen(sep);
		}
		i++;
	}
	return (result);
}
/*
int main() {
  int size = 3;
   char *strs[] = {
       "Hive"
      "Coding",
           "School"
    };
    char *sep = "! ";
    char *res = ft_strjoin(size, strs, sep);
    if (res != 0) 
    {
        printf("%s\n", res);
        free(res);
    } 
    else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
*/
