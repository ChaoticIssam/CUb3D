/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:35:27 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/03 23:33:19 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	items_check(t_main *m)
{
	around_floor(m);
	if ((dir_path(m) == NULL && m->p->count_paths != 4))
		path_error();
	else if((floor_ceiling(m) == NULL && m->c->count_rgb != 2) || merge_floor_color(m) == -1 || merge_ceiling_color(m) == -1)
		color_error();
	printf("rgb ->>>%d\n", merge_floor_color(m));
	printf("north ->%s\nsouth ->%s\nwest ->%s\neast ->%s\n", m->p->north_path, m->p->south_path, m->p->west_path, m->p->east_path);
	map_check_first(m);
	map_check_last(m);
	invalid_item(m);
	p_check(m);
}

int	line_count(t_main *m)
{
	int	i;

	i = map_frst_line(m);
	if (!m->map)
		return (0);
	while (m->map[i])
		i++;
	i--;
	return (i);
}

int	line_len(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return (0);
	while (s[j])
		j++;
	return (j);
}

int	map_check_first(t_main *m)
{
	int	i;
	int	j;

	i = map_frst_line(m);
	j = 0;
	if (!m->map || !*m->map)
		return (0);
	while (m->map[i][j])
	{
		if (m->map[i][j] != '1' && m->map[i][j] != ' ' && m->map[i][j] != '\t')
			horinzontal_error();
		j++;
	}
	return (j);
}

int	map_check_last(t_main *m)
{
	int	i;
	int	j;

	j = 0;
	if (!m->map || !*m->map)
		return (0);
	i = line_count(m);
	while (m->map[i][j])
	{
		if (m->map[i][j] != '1' && m->map[i][j] != ' ')
			horinzontal_error();
		j++;
	}
	return (j);
}
