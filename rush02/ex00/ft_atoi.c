/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:21:58 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/16 13:54:24 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	numb_check(char *str, unsigned int i, unsigned int num)
{
	while (str[i] != '\0')
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			num *= 10;
			num += (unsigned int)str[i] - 48;
			i++;
		}
		i++;
		return (num);
	}
	return (0);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	num;
	unsigned int	i;
	unsigned int	res;

	i = 0;
	num = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
	{
		i++;
	}
	res = numb_check(str, i, num);
	return (res);
}
