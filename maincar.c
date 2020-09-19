/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:39:07 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 21:26:16 by mvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char **tab_arg;
	int i;
	int j;

	if (argc != 2)
		return (0);
	i = 0;
	tab_arg = (char **)malloc(4 * sizeof(char *));
	while (i < 4)
	{
		tab_arg[i] = (char *)malloc(4 * sizeof(char));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab_arg[i][j] = '0';
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
			write(1, &tab_arg[i][j] , 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
