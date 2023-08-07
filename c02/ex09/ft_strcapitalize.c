/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:59:15 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/03 15:57:37 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_an(char ch)
{
	return ((ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z')
		|| (ch >= '0' && ch <= '9')
	);
}

char	to_upper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return (ch - 32);
	}
	return (ch);
}

char	to_lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return (ch + 32);
	}
	return (ch);
}

int	condition(char *str, int i)
{
	if (is_an(*str))
	{
		if (i)
		{
			*str = to_upper(*str);
			i = 0;
		}
		else
		{
			*str = to_lower(*str);
		}
	}
	else
	{
		i = 1;
	}
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int		upper_next;
	char	*ptr;

	upper_next = 1;
	ptr = str;
	while (*str != '\0')
	{
		upper_next = condition(str, upper_next);
		str++;
	}
	return (ptr);
}
