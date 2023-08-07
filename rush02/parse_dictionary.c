/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:56:26 by rboudwin          #+#    #+#             */
/*   Updated: 2023/07/16 18:16:41 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	ignore_white_space(char *buffer, int i)
{
	while ((buffer[i] == '\t') || (buffer[i] == '\v')
		|| (buffer[i] == '\f') || (buffer[i] == '\r')
		|| (buffer[i] == ' ') || (buffer[i] == ':'))
		i++;
	return (i);
}

int	check_for_complete_struct(t_rule *rule_array, int j)
{
	if (rule_array[j].key >= 0 && rule_array[j].word != '\0')
		return (1);
	else
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
}

int	end_of_line_check(char *buffer, int *i_ptr, int k, int *colon_ptr)
{
	if (buffer[*i_ptr] == '\n')
	{
		if (*colon_ptr != 1)
		{
			ft_putstr("Dict Error\n");
			return (1000000);
		}
		*colon_ptr = 0;
		*(i_ptr) = *(i_ptr) + 1;
		k++;
	}		
	return (k);
}

// this controls the general flow of the dictionary parsing
t_rule	*parse_dictionary(char *buffer, int line_count, int i, int j)
{
	t_rule	*rule_array;
	int		k;
	int		colon_flag;

	k = 0;
	colon_flag = 0;
	rule_array = handle_malloc_rule_array(line_count);
	while (buffer[i] != '\0' && k < line_count)
	{
		if (buffer[i] == ':' && colon_flag == 0)
			colon_flag = 1;
		k = end_of_line_check(buffer, &i, k, &colon_flag);
		i = ignore_white_space(buffer, i);
		i = make_keys(buffer, rule_array, i, j);
		if (i == -1)
			return (NULL);
		if (buffer[i] > 32 && buffer[i] <= 127 && buffer[i] != 58 && k++ != -1)
		{
			buffer = copy_word(buffer + i, rule_array, j);
			if (buffer == 0 || check_for_complete_struct(rule_array, j++) == 0)
				return (NULL);
			i = 1;
		}
	}
	return (rule_array);
}
