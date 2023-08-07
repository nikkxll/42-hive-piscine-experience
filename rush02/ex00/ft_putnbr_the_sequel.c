/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_the_sequel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:03:23 by rboudwin          #+#    #+#             */
/*   Updated: 2023/07/16 15:58:03 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// This function composing result string
char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
	{
		tmp++;
	}
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = '\0';
	return (dest);
}

// This function takes an index from the dictionary
// according to the number we pass
int	get_index(t_rule *numberPairs, unsigned int number)
{
	unsigned int	i;

	i = 0;
	while (i < 1000)
	{
		if (numberPairs[i].key == number)
			return (i);
		i++;
	}
	return (-1);
}

// This function puts the word into the result string one by one
void	ft_str_create(t_rule *numberPairs, unsigned int counter, char *str)
{
	unsigned int	index;

	index = get_index (numberPairs, counter);
	ft_strcat(str, numberPairs[index].word);
	ft_strcat(str, " ");
}

// Putting thousand, million or billion into the result string depending on
// the flag. If check is 0 (sum of digits) - do nothing.
void	ft_place(t_rule *numberPairs, int flag, unsigned int check, char *str)
{
	unsigned int	counter;

	counter = 1;
	if (check)
	{
		while (flag--)
			counter *= THOUSAND;
		if (counter == BILLION)
			ft_str_create(numberPairs, counter, str);
		else if (counter == MILLION)
			ft_str_create(numberPairs, counter, str);
		else if (counter == THOUSAND)
			ft_str_create(numberPairs, counter, str);
	}
}
