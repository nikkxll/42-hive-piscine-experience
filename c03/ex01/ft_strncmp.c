/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:28:49 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/04 20:01:29 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
	{
		return (0);
	}
	n--;
	while (*s1 != '\0' && n-- && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}