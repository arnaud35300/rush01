/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:21:34 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 15:35:07 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	int **tab;

	i = -1;
	tab = (int **)malloc(sizeof(*tab) * 4);
	while (++i < 4)
		tab[i] = (int *)malloc(sizeof(tab) * 4);
	return (0);
}
