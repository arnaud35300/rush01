/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:33:52 by spoliart          #+#    #+#             */
/*   Updated: 2020/09/19 13:59:11 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	verif_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '1' && str[i] > '4') || (str[i + 1] != ' ' && i < 30))
			return (0);
		i += 2;
	}
	if (i != 31)
		return (0);
	return (1);
}