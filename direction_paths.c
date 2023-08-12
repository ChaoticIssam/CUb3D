/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:08:33 by iszitoun          #+#    #+#             */
/*   Updated: 2023/08/11 14:07:26 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dir_var_init(t_dir *dir)
{
	dir->i = 0;
	dir->j = 0;
	dir->n = 0;
	dir->s = 0;
	dir->w = 0;
	dir->e = 0;
}

void	allocat_dir(t_main *m)
{
	m->p->north_path = malloc(sizeof(char) * 100);
	m->p->south_path = malloc(sizeof(char) * 100);
	m->p->west_path = malloc(sizeof(char) * 100);
	m->p->east_path = malloc(sizeof(char) * 100);
}

char	*dir_path(t_main *m)
{
	t_dir	*dir;

	dir = malloc(sizeof(t_dir));
	m->p = malloc(sizeof(t_paths));
	allocat_dir(m);
	dir_var_init(dir);
	while (m->map[dir->i] && dir->i < map_frst_line(m))
	{
		dir->j = 0;
		while (m->map[dir->i][dir->j] == ' ' || m->map[dir->i][dir->j] == '\t')
		{
			dir->j++;
			if (m->map[dir->i][dir->j] == '\n')
				dir->i++;
			for_north(m, dir);
			for_south(m, dir);
			for_west(m, dir);
			for_east(m, dir);
		}
		for_north(m, dir);
		for_south(m, dir);
		for_west(m, dir);
		for_east(m, dir);
		dir->i++;
	}
	return (NULL);
}

void	for_north(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'N' && m->map[dir->i][dir->j + 1] == 'O')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->north_path[dir->n] = m->map[dir->i][dir->j];
			dir->n++;
			dir->j++;
		}
		m->p->north_path[dir->n] = '\0';
		m->p->count_paths++;
	}
}

void	for_south(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'S' && m->map[dir->i][dir->j + 1] == 'O')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->south_path[dir->s] = m->map[dir->i][dir->j];
			dir->s++;
			dir->j++;
		}
		m->p->south_path[dir->s] = '\0';
		m->p->count_paths++;
	}
}

void	for_west(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'W' && m->map[dir->i][dir->j + 1] == 'E')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->west_path[dir->w] = m->map[dir->i][dir->j];
			dir->w++;
			dir->j++;
		}
		m->p->west_path[dir->w] = '\0';
		m->p->count_paths++;
	}
}

void	for_east(t_main *m, t_dir *dir)
{
	if (m->map[dir->i][dir->j] == 'E' && m->map[dir->i][dir->j + 1] == 'A')
	{
		dir->j = dir->j + 2;
		while (m->map[dir->i][dir->j] && (m->map[dir->i][dir->j] == ' '
				|| m->map[dir->i][dir->j] == '\t'))
			dir->j++;
		while (m->map[dir->i][dir->j] && m->map[dir->i][dir->j] != '\n')
		{
			m->p->east_path[dir->e] = m->map[dir->i][dir->j];
			dir->e++;
			dir->j++;
		}
		m->p->east_path[dir->e] = '\0';
		m->p->count_paths++;
	}
}
