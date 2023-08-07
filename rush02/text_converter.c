/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:22:59 by rboudwin          #+#    #+#             */
/*   Updated: 2023/07/16 18:36:24 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

/* this function makes sure we free all our allocated memory and 
 * prints the final answer to the stdout*/
void	run_final_cleanup(t_rule *rules_array, char *buffer, char *final_string)
{
	int	i;
	int	z;

	i = 0;
	while (final_string[i + 1] != '\0')
		i++;
	final_string[i] = '\n';
	ft_putstr(final_string);
	free(buffer);
	z = 0;
	while (rules_array[z].key != 1000000000)
	{
		free(rules_array[z].word);
		z++;
	}
	free(rules_array[z].word);
	free(rules_array);
}

int	count_lines(char *buffer)
{
	int	i;
	int	line_count;

	line_count = 0;
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			line_count++;
		}
		i++;
	}
	return (line_count);
}

char	*open_and_read(char *dictionary)
{
	int		file_id;	
	int		did_it_close;
	char	*buffer;

	buffer = malloc(10000 * sizeof(char));
	if (buffer == NULL)
	{
		ft_putstr("Error: Our buffer malloc failed");
		return (NULL);
	}
	file_id = open(dictionary, O_RDONLY);
	if (file_id == -1)
		ft_putstr("Error: specified dictionary file does not exist");
	read(file_id, buffer, 10000);
	did_it_close = close(file_id);
	if (did_it_close == -1)
		ft_putstr("Error: Unable to close dictionary file");
	return (buffer);
}

void	ft_convert_to_text(int number, char *dictionary)
{
	char	*buffer;
	int		line_count;
	t_rule	*rules_array;
	char	blank_string[500];
	char	*final_string;

	buffer = open_and_read(dictionary);
	if (buffer == NULL)
		return ;
	line_count = count_lines(buffer);
	rules_array = parse_dictionary(buffer, line_count, 0, 0);
	if (rules_array == NULL)
	{
		free(buffer);
		return ;
	}
	final_string = ft_putnbr(rules_array, number, 0, blank_string);
	run_final_cleanup(rules_array, buffer, final_string);
}
