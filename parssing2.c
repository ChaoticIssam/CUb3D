/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:39:20 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/08 18:43:06 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalid_item(t_main *m)
{
	int	i;
	int	j;

	i = map_frst_line(m);
	j = 1;
	while (++i < line_count(m))
	{
		j = 0;
		while (m->map[i][++j])
		{
			if (m->map[i][j] != '1' && m->map[i][j] != '0' && (m->map[i][j] != 'N'
					&& m->map[i][j] != 'S' && m->map[i][j] != 'E' && m->map[i][j] != 'W')
				&& m->map[i][j] != ' ' && m->map[i][j] != '\t')
					invalid_item_error();
		}
	}
}

int	p_check(t_main *m)
{
	int i;
	int j;
	int count;

	i = map_frst_line(m);
	j = 1;
	count = 0;
	while (++i < line_count(m))
	{
		j = 0;
		while (m->map[i][++j])
		{
			if (m->map[i][j] == 'N' || m->map[i][j] == 'S' || m->map[i][j] == 'E' || m->map[i][j] == 'W')
			{
				m->pos_y = i;
				m->pos_x = j;
				count++;
			}
		}
	}
	if (count != 1)
		duplicated_player_error();
	return (1);
}