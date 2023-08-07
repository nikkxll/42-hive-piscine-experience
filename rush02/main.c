/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:09:01 by rboudwin          #+#    #+#             */
/*   Updated: 2023/07/16 18:16:27 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	validate_input(char *str)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	while (str[i] != '\0')
	{	
		if (str[i] >= '0' && str[i] <= '9')
		{	
			i++;
			digits++;
		}
		else
			return (0);
		if (digits > 10)
			return (0);
	}
	return (1);
}

int	check_over_max(unsigned int number)
{
	if (number <= 4294967295 && number > 0)
		return (0);
	else
	{
		ft_putstr("Error: Input is not a valid unsigned integer");
		return (1);
	}
}

//allows the user to specify their own dictionary
void	choose_dictionary(int number, int argc, char **argv)
{	
	if (argc == 3)
		ft_convert_to_text(number, argv[1]);
	else
		ft_convert_to_text(number, "numbers.dict");
}

// confirms we have the right number of arguments
// and that the number we were provided is a valid
// unsigned integer
int	master_arg_control(int argc, char **argv)
{
	unsigned int	number;
	int				argindex;
	int				valid_input;
	int				over_max;

	if (argc > 3 || argc < 2)
	{
		ft_putstr("Error: invalid number of arguments\n");
		return (0);
	}
	argindex = 1;
	if (argc == 3)
		argindex = 2;
	valid_input = validate_input(argv[argindex]);
	if (valid_input == 1)
	{	
		number = ft_atoi(argv[argindex]);
		over_max = check_over_max(number);
		if (over_max == 1)
			return (0);
	}
	else
		return (0);
	choose_dictionary(number, argc, argv);
	return (1);
}

int	main(int argc, char **argv)
{
	int	valid_input;

	valid_input = master_arg_control(argc, argv);
	if (valid_input == 0)
	{
		ft_putstr("Error: Argument is not a valid unsigned integer \n");
		return (0);
	}
}
