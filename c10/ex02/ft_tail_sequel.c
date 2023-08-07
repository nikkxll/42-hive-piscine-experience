/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_sequel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:07:50 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/20 20:42:04 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int	numb_check(char *str, int sign, int i, int num)
{
	while (str[i] != '\0')
	{
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
			{
				sign = sign * -1;
			}
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			num *= 10;
			num += str[i] - '0';
			i++;
		}
		i++;
		return (sign * num);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	i;
	int	res;

	i = 0;
	num = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
	{
		i++;
	}
	sign = 1;
	res = numb_check(str, sign, i, num);
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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

int	print_error(char *message)
{
	write(STDERR_FILENO, message, ft_strlen(message));
	return (1);
}
