/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:21:58 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/05 20:09:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
