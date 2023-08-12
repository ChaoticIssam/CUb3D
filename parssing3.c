/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:46:59 by iszitoun          #+#    #+#             */
/*   Updated: 2023/08/10 16:53:25 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\0' || c == '\t')
		return (1);
	return (0);
}

void	around_floor(t_main *m)
{
	int i;
	int j;

	i = map_frst_line(m);
	j = 1;
	while (m->map[i])
	{
		j = 1;
		while (m->map[i][j])
		{
			if ((m->map[i][j] == '0' || m->map[i][j] == 'N')
				&& (white_space(m->map[i + 1][j]) || white_space(m->map[i
						- 1][j])))
				void_next_floor();
			j++;
		}
		i++;
	}
}