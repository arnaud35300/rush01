/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_is_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoltair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:23:58 by mvoltair          #+#    #+#             */
/*   Updated: 2020/09/20 16:28:07 by agbosch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vis_col_up(char **tab, int row);

int	vis_col_down(char **tab, int row);

int	vis_row_left(char **tab, int col);

int	vis_row_right(char **tab, int col);

int	tab_is_ok(char **tab_res, char **tab_arg)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab_arg[0][i] != vis_col_up(tab_res, i))
			return (0);
		if (tab_arg[1][i] != vis_col_down(tab_res, i))
			return (0);
		if (tab_arg[2][i] != vis_row_left(tab_res, i))
			return (0);
		if (tab_arg[3][i] != vis_row_right(tab_res, i))
			return (0);
		i++;
	}
	return (1);
}
