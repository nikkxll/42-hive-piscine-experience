/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dictionary_the_sequel.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:49:46 by rboudwin          #+#    #+#             */
/*   Updated: 2023/07/16 18:16:03 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*copy_word(char *mod_buffer, t_rule *rule_array, int j)
{
	int	i;

	i = 0;
	rule_array[j].word = malloc(100);
	if (rule_array[j].word == NULL)
	{
		ft_putstr("Error: rule_array.word malloc failed");
		return (NULL);
	}
	while (mod_buffer[i] != '\0' && mod_buffer[i] != '\n')
	{
		rule_array[j].word[i] = mod_buffer[i];
		i++;
	}
	if (mod_buffer[i] == '\n')
		rule_array[j].word[i] = '\0';
	return (mod_buffer + i);
}

t_rule	*handle_malloc_rule_array(int line_count)
{
	t_rule	*rule_array;

	rule_array = malloc(sizeof(t_rule) * line_count);
	if (rule_array == NULL)
	{
		ft_putstr("Error: rule_array malloc failed \n");
		return (NULL);
	}
	else
		return (rule_array);
}

// this function sets the numbers provided in the dictionary
// to the key field of our struct
int	make_keys(char *buffer, t_rule *rule_array, int i, int j)
{
	if (buffer[i] >= '0' && buffer[i] <= '9')
	{
		if (j != 0)
		{
			if (rule_array[j].key != 0)
			{
				ft_putstr("Dict Error\n");
				return (-1);
			}
		}
		rule_array[j].key = ft_atoi(buffer + i);
		while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	}
	return (i);
}
