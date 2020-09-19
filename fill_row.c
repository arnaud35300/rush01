/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:10:16 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/20 00:03:21 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		tab_is_ok(char **tabi, char **tab_arg);

void	ft(char ***board, int *row, char a, char b, char **tab_arg);

int		row_ok(char **board, int row);

char	**fill_row(char **board, int row, char **tab_arg)
{
	char a;
	char b;
	char c;
	char d;

	if (row >= 4)
	{
		if (tab_is_ok(board, tab_arg))
		{
			write(1, "nique", 5);
			return (board);
		}
		else
			write(1, "Error\n", 6);
		return (board);
	}
	a = '0';
	while (++a <= '4')
	{
		board[row][0] = a;
		b = '0';
		ft(&board, &row, a, b, tab_arg);
	}
	return (board);
}

void	ft(char ***board, int *row, char a, char b, char **tab_arg)
{
	char d;
	char c;

	while (++b <= '4')
	{
		if (a == b)
			continue ;
		*board[*row][1] = b;
		c = '0';
		while (++c <= '4')
		{
			if (a == c || b == c)
				continue ;
			*board[*row][2] = c;
			d = '0';
			while (++d <= '4')
			{
				if (a == d || b == d || c == d)
					continue ;
				*board[*row][3] = d;
				if (row_ok(*board, *row))
					fill_row(*board, *row + 1, tab_arg);
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
	{
		while (++i <= row)
		{
			if (board[i][col] == board[row][col])
				return (0);
		}
	}
	return (1);
}
