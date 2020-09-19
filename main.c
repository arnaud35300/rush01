/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:39:07 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 20:06:09 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_atoi(char *str, int ***tab)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 4)
		{
			*tab[i][j] = str[i] - '0';
			j++;
		}
		i += 2;
	}
}

int		main(int argc, char **argv)
{
	int **tab_arg;
	int i;
	int j;

	if (argc != 2)
		return (0);
	i = -1;
	tab_arg = (int **)malloc(4 * sizeof(int *));
	while (++i < 4)
	{
		tab_arg[i] = (int *)malloc(4 * sizeof(int));
	}
	ft_atoi(*argv, &tab_arg);
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab_arg[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &tab_arg[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
