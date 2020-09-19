/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:10:16 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 19:31:04 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		**ft(int ***board, int *row, int a, int b, int c);

int		row_ok(int **board, int row);

void	fill_row(int **board, int row)
{
	int a;
	int b;
	int c;
	int d;

	if (row == 4)
	{
		if (visu_ok(board))
			print(board);
		return ;
	}
	a = 0;
	while (++a <= 4)
	{
		board[row][0] = a;
		b = 0;
		ft(board, row, a, b, c, d);
	}
}

int		**ft(int ***board, int *row, int a, int b, int c)
{
	while (++b <= 4)
	{
		if (a == b)
			continue;
		*board[row][1] = b;
		c = 0;
		while (++c <= 4)
		{
			if (a == c || b == c)
				continue;
			*board[row][2] = c;
			d = 0;
			while (++d <= 4)
			{
				if (a == d || b == d || c == d)
					continue;
				*board[row][3] = d;
				if (row_ok(board, row))
					fill_row(board, row + 1);
			}
		}
	}
}

int		row_ok(int **board, int row)
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
