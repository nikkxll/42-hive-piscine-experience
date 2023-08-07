/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:35:07 by akovalev          #+#    #+#             */
/*   Updated: 2023/07/17 14:12:30 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (0);
}
/*
int	main()
{
	char *s = "Hello everyone";
	char c = 'e';

	printf("%s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
}*/
