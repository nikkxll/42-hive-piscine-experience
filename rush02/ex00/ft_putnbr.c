/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:28:31 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/16 16:09:08 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// This function write two-digit number into the string 
// in words
void	two_digit_nbr(t_rule *numberPairs, unsigned int num,
		unsigned int tmp, char *str)
{
	tmp = num - num % 10;
	ft_str_create(numberPairs, tmp, str);
	num = num - tmp;
	ft_str_create(numberPairs, num, str);
}

// This function check if the number is non-composed one
// (composed one - took two or more rules from dict)
// (non-composed one - took just one rules)
// and put it into result string either if it is
// composed or non-composed
unsigned int	ft_check_three_digits(t_rule *numberPairs,
		unsigned int num, unsigned int tmp, char *str)
{
	num = num - tmp * HUNDRED;
	if ((num > 0 && num <= 9) || (num >= 11 && num <= 19)
		|| (num % 10 == 0 && num != 0))
		ft_str_create(numberPairs, num, str);
	else if (num != 0)
		two_digit_nbr(numberPairs, num, tmp, str);
	return (num);
}

// This function checks how many digits num has and
// put words according to conditions
void	ft_hundred(t_rule *numberPairs, unsigned int num, char *str)
{
	unsigned int	tmp;
	unsigned int	index;

	index = 0;
	tmp = 0;
	if (num / HUNDRED > 0)
	{
		tmp = num / HUNDRED;
		ft_str_create(numberPairs, tmp, str);
		ft_str_create(numberPairs, HUNDRED, str);
		num = ft_check_three_digits(numberPairs, num, tmp, str);
	}
	else if ((num / HUNDRED == 0) && (num / 10 > 0))
	{
		if ((num > 0 && num <= 9) || (num >= 11 && num <= 19)
			|| (num % 10 == 0 && num != 0))
			ft_str_create(numberPairs, num, str);
		else
			two_digit_nbr(numberPairs, num, tmp, str);
	}
	else if ((num / HUNDRED == 0) && (num / 10 == 0) && (num > 0))
		ft_str_create(numberPairs, num, str);
}

/* This function do recursion to got the power of thousand in the number
by increasing the flag. Then calling functions when going backwards from
recursion to write words into the result string. Also doing check to calculate 
the sum of the digits and check if it is more than 0 or not*/
char	*ft_putnbr(t_rule *numberPairs, unsigned int nb, int flag, char *str)
{
	unsigned int	check;

	if (nb == 0)
	{
		ft_str_create(numberPairs, 0, str);
	}
	if (nb < THOUSAND)
	{
		ft_hundred (numberPairs, nb, str);
		ft_place (numberPairs, flag, 1, str);
	}
	else
	{
		ft_putnbr (numberPairs, nb / THOUSAND, flag + 1, str);
		ft_hundred (numberPairs, nb % THOUSAND, str);
		nb = nb % THOUSAND;
		check = nb / HUNDRED + nb % HUNDRED / 10 + nb % 10;
		ft_place (numberPairs, flag, check, str);
	}
	return (str);
}
