/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 14:39:07 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 18:03:52 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**ft_atoi(char *str)
{
	int i;
	int j;
	int **tab;

	i = 0;
	j = 0;
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


int	main(int argc, char **argv)
{
	int **tab;
	tab = ft_atoi(argv);
}
