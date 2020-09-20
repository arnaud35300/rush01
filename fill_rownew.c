/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:10:16 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/20 17:36:48 by agbosch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		tab_is_ok(char **tab, char **tab_arg);

int		row_ok(char **board, int row);

char	fill_row2_bis(char **board, int row, char **tab_arg);

void	ft_print(char **tab)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			write(1, &tab[i][j], 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

char	fill_row2(char **board, int row, char **tab_arg)
{
	char eureka;

	ft_print(board);
	if (row >= 4) 
		return (tab_is_ok(board, tab_arg));
	eureka = 0;
	board[row][0] = '0';
	while (board[row][0]++ <= '3' && !eureka)
	{
		board[row][1] = '0';
		while (board[row][1]++ <= '3' && !eureka)
		{
			if(board[row][1] == board[row][0]) 
				continue ;
			eureka = fill_row2_bis(board, row, tab_arg);
		}
	}
	return (eureka);
}

char	fill_row2_bis(char **board, int row, char **tab_arg)
{
	char eureka;

	eureka = 0;
	board[row][2] = '0';
	while (board[row][2]++ <= '3' && !eureka)
	{
		if(board[row][2] == board[row][0] || board[row][2] == board[row][1]) 
			continue ;
		board[row][3] = '0';
		while (board[row][3]++ <= '3' && !eureka)
		{
			if(board[row][3] == board[row][0] || board[row][3] == board[row][1]
				|| board[row][3] == board[row][2]) 
				continue ;
			if (row_ok(board, row))
				eureka = fill_row2(board, row + 1, tab_arg);
		}
	}
	return (eureka);
}

int		row_ok(char **board, int row)
{
	int i;
	int col;

	col = -1;
	while (++col < 4)
	{
		i = -1;
		while (++i < row)
			if (board[i][col] == board[row][col])
				return (0);
	}
	return (1);
}
