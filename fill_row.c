/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:10:16 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/20 13:31:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		tab_is_ok(char **tab, char **tab_arg);

void	ft(char ***board, int row, char a, char b);

int		row_ok(char **board, int row);

void	ft_print(char **tab)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			write(1, &tab[i][j], 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

char	**fill_row(char **board, int row, char **tab_arg)
{
	char a;
	char b;

	if (row >= 4)
	{
		if (tab_is_ok(board, tab_arg))
		{
			return (board);
		}
		else
			write(1, "Error\n", 6);
		return (0);
	}
	a = '0';
	while (++a <= '4')
	{
		ft_print(board);
		board[row][0] = a;
		b = '0';
		ft(&board, row, a, b);
		if (row_ok(board, row))
			fill_row(board, row + 1, tab_arg);
	}
	return (0);
}

void	ft(char ***board, int row, char a, char b)
{
	char d;
	char c;

	while (++b <= '4')
	{
		if (a == b)
			continue ;
		*board[row][1] = b;
		c = '0';
		while (++c <= '4')
		{
			if (a == c || b == c)
				continue ;
			*board[row][2] = c;
			d = '0';
			while (++d <= '4')
			{
				if (a == d || b == d || c == d)
					continue ;
				*board[row][3] = d;
			}
		}
	}
}

int		row_ok(char **board, int row)
{
	int i;
	int col;

	i = -1;
	col = -1;
	while (++col <= 4)
		while (++i <= row)
			if (board[i][col] == board[row][col])
				return (0);
	return (1);
}
