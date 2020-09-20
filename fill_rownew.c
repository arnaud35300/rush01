/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:10:16 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/20 13:46:12 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		tab_is_ok(char **tab, char **tab_arg);

void	ft(char **board, int row, char a, char b);

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

char fill_row2(char **board, int row, char **tab_arg)
{
	char eureka;
	
	if (row >= 4) 
		return (tab_is_ok(board, tab_arg)) ;

	eureka = 0;
	board[row][0] = '0';
	while (++board[row][0] <= '4' && !eureka)
	{
		board[row][1]='0';
		while (++board[row][1] <= '4' && !eureka)
		{
			if(board[row][1]==board[row][0]) 
				continue;
			eureka = fill_row2_bis(board, row, tab_arg);
		}
	}
	return eureka;
}

char fill_row2_bis(char **board, int row, char **tab_arg){
	char eureka;
	eureka = 0;
	board[row][2]='0';
	while (++board[row][2] <= '4' && !eureka)
	{
		if(board[row][2]==board[row][0] || board[row][2]==board[row][1]) 
			continue;
		board[row][3]='0';
		while (++board[row][3] <= '4' && !eureka)
		{
			if(board[row][3]==board[row][0] || board[row][3]==board[row][1] || board[row][3]==board[row][2]) 
				continue;
			if (row_ok(board, row)) eureka = fill_row2(board, row + 1, tab_arg);
		}
	}
	return eureka;
}

void	ft(char **board, int row, char a, char b)
{
	char d;
	char c;

	while (++b <= '4')
	{
		if (a == b)
			continue ;
		board[row][1] = b;
		c = '0';
		while (++c <= '4')
		{
			if (a == c || b == c)
				continue ;
			board[row][2] = c;
			d = '0';
			while (++d <= '4')
			{
				if (a == d || b == d || c == d)
					continue ;
				board[row][3] = d;
				if (row_ok(board, row))
					fill_row(board, row + 1, tab_arg);
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
	if (row == 0)
		return (0);
	while (++col <= 4)
		i = -1;
		while (++i < row)
			if (board[i][col] == board[row][col])
				return (0);
	return (1);
}
