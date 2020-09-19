/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:39:07 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 22:13:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_print(char **tab)
{
	int i;
	int j;

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
}

void	ft_create_tab(char ***tab_res, char ***tab_arg)
{
	int i;

	i = -1;
	*tab_arg = (char **)malloc(4 * sizeof(char *));
	*tab_res = (char **)malloc(4 * sizeof(char *));
	while (++i < 4)
	{
		*tab_arg[i] = (char *)malloc(4 * sizeof(char));
		*tab_res[i] = (char *)malloc(4 * sizeof(char));
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	char **tab_arg;
	char **tab_res;

	if (argc != 2)
		return (0);
	ft_create_tab(&tab_res, &tab_arg);
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tab_arg[i][j] = argv[1][k];
			k += 2;
		}
	}
	ft_print(tab_arg);
	free(tab_res);
	free(tab_arg);
	return (0);
}
