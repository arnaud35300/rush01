/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:39:07 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 18:33:46 by tpatroui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	**ft_atoi(char *str)
{
	int i;
	int j;
	int **tab;

	tab = malloc(4 * sizeof(int *));
	i = -1;
	while (++i < 4)
		tab[i] = malloc(4 * sizeof(int));
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
	int **tab;
	int **tabv;
	int i;
	int j;

	(void)argc;
	tab = malloc(4 * sizeof(int *));
	tabv = malloc(4 * sizeof(int *));
	i = -1;
	while (++i < 4)
		tab[i] = malloc(4 * sizeof(int));
	tabv = ft_atoi(*argv);
	i = 0; 
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
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
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
