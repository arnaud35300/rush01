/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:39:07 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 19:34:04 by tpatroui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	**ft_atoi(char *str)
{
	int i;
	int j;
	int **tab;

	tab = malloc(4 * sizeof(int *));
	i = -1;
	while (++i < 4)
		tab[i] = malloc(4 * sizeof(int *));
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = str[i] - '0';
			j++;
		}
		i += 2;
	}
	return (tab);
}

int main(int argc, char **argv)
{
	int **tab_arg;
	int **tab_res;
	int i;
	int j;

	if (argc != 2)
		return (0);
	tab_arg = malloc(4 * sizeof(int *));
	tab_res = malloc(4 * sizeof(int *));
	i = -1;
	while (++i < 4)
		tab_arg[i] = malloc(4 * sizeof(int *));
	tab_res = ft_atoi(*argv);
	i = -1;
	while (++i < 4)
	{
		tab_arg[i] = malloc(4 * sizeof(int *));
	}
	ft_atoi(*argv);
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
