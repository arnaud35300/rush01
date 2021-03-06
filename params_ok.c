/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoltair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:16:41 by mvoltair          #+#    #+#             */
/*   Updated: 2020/09/20 16:36:35 by agbosch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vis_row_left(char **tab, int col)
{
	int i;
	char max_so_far;
	int vis_so_far;

	i = 0;
	max_so_far = '0';
	vis_so_far = 0;
	while (i < 4)
	{
		if (tab[col][i] > max_so_far)
		{
			max_so_far = tab[col][i];
			vis_so_far += 1;
		}
		i++;
	}
	return (vis_so_far);
}

int	vis_row_right(char **tab, int col)
{
	int i;
	char max_so_far;
	int vis_so_far;

	i = 3;
	max_so_far = '0';
	vis_so_far = 0;
	while (i >= 0)
	{
		if (tab[col][i] > max_so_far)
		{
			max_so_far = tab[col][i];
			vis_so_far += 1;
		}
		i--;
	}
	return (vis_so_far);
}

int	vis_col_up(char **tab, int row)
{
	int i;
	char max_so_far;
	int vis_so_far;

	i = 0;
	max_so_far = '0';
	vis_so_far = 0;
	while (i < 4)
	{
		if (tab[i][row] > max_so_far)
		{
			max_so_far = tab[i][row];
			vis_so_far += 1;
		}
		i++;
	}
	return (vis_so_far);
}

int	vis_col_down(char **tab, int row)
{
	int i;
	char max_so_far;
	int vis_so_far;

	i = 3;
	max_so_far = '0';
	vis_so_far = 0;
	while (i >= 0)
	{
		if (tab[i][row] > max_so_far)
		{
			max_so_far = tab[i][row];
			vis_so_far += 1;
		}
		i--;
	}
	return (vis_so_far);
}
