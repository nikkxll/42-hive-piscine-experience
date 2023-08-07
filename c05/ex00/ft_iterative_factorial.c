/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:07:40 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/06 11:09:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb >= 0)
	{
		while (nb)
		{
			i = i * nb--;
		}
		return (i);
	}
	return (0);
}
