/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:29:21 by dnikifor          #+#    #+#             */
/*   Updated: 2023/07/02 12:50:37 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	cnd(int line, int col, int x, int y)
{
	if (line == 0 || line == y - 1)
	{
		if (col == 0 || col == x - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
	}
	else
	{
		if (col == 0 || col == x - 1)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
	}
}

void	rush(int x, int y)
{
	int	line;
	int	col;

	line = 0;
	while (line < y)
	{
		col = 0;
		while (col < x)
		{
			cnd(line, col, x, y);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
