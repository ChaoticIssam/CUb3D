/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:46:59 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/08 16:00:37 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sides(t_main *m)
{
	int	i;
	int	j;

	i = map_frst_line(m);
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (white_space(m->map[i][j]))
			j++;
		if (m->map[i][j] != '1' || m->map[i][line_len(m->map[i]) - 1] != '1')
			sides_error();
		i++;
	}
}

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
						- 1][j]) || white_space(m->map[i][j + 1]) || white_space(m->map[i][j - 1])))
				void_next_floor();
			j++;
		}
		i++;
	}
}