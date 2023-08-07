/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:55:48 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/06 19:21:55 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		return (0);
	}
	i = 1;
	while (i * i <= (unsigned int)nb)
	{
		if (i * i == (unsigned int)nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
