/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:56:03 by asohrabi          #+#    #+#             */
/*   Updated: 2023/07/19 10:58:53 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strnlen(char *str, int max_len);
char	*ft_memcpy(char *dest, char *src, int n);

char	*ft_strndup(char *str, int n)
{
	int		length;
	char	*result;
	
	length = ft_strnlen(str, n);
	result = (char*)malloc(length + 1);
	if (result != NULL)
	{
		ft_memcpy(result, str, length);
		result[length] = '\0';
	}
	return (result);
}
