/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:03:19 by iszitoun          #+#    #+#             */
/*   Updated: 2023/08/11 17:37:30 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*floor_ceiling(t_main *m)
{
	int	i;
	int	j;
	int	f;
	int	c;

	i = 0;
	j = 0;
	f = 0;
	c = 0;
	m->c = malloc(sizeof(t_colors));
	m->c->ceiling_color = malloc(sizeof(char) * 100);
	m->c->floor_color = malloc(sizeof(char) * 100);
	while (m->map[i] && i < map_frst_line(m))
	{
		j = 0;
		while (m->map[i][j] && (m->map[i][j] == ' ' || m->map[i][j] == '\t'))
		{
			j++;
			if (m->map[i][j] == '\n')
				i++;
			if (m->map[i][j] == 'F')
			{
				j++;
				while (m->map[i][j] && (m->map[i][j] == ' '
						|| m->map[i][j] == '\t'))
					j++;
				while (m->map[i][j] && m->map[i][j] != '\n')
				{
					m->c->floor_color[f] = m->map[i][j];
					f++;
					j++;
				}
				m->c->floor_color[f] = '\0';
				m->c->count_rgb++;
			}
			else if (m->map[i][j] == 'C')
			{
				j++;
				while (m->map[i][j] && (m->map[i][j] == ' '
						|| m->map[i][j] == '\t'))
					j++;
				while (m->map[i][j] && m->map[i][j] != '\n')
				{
					m->c->ceiling_color[c] = m->map[i][j];
					c++;
					j++;
				}
				m->c->ceiling_color[c] = '\0';
				m->c->count_rgb++;
			}
		}
		if (m->map[i][j] == 'F')
		{
			j++;
			while (m->map[i][j] && (m->map[i][j] == ' '
					|| m->map[i][j] == '\t'))
				j++;
			while (m->map[i][j] && m->map[i][j] != '\n')
			{
				m->c->floor_color[f] = m->map[i][j];
				f++;
				j++;
			}
			m->c->floor_color[f] = '\0';
			m->c->count_rgb++;
		}
		else if (m->map[i][j] == 'C')
		{
			j++;
			while (m->map[i][j] && (m->map[i][j] == ' '
					|| m->map[i][j] == '\t'))
				j++;
			while (m->map[i][j] && m->map[i][j] != '\n')
			{
				m->c->ceiling_color[c] = m->map[i][j];
				c++;
				j++;
			}
			m->c->ceiling_color[c] = '\0';
			m->c->count_rgb++;
		}
		i++;
	}
	return (NULL);
}

int	merge_floor_color(t_main *m)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	r = -1;
	g = -1;
	b = -1;
	printf("%s\n", m->c->floor_color);
	while (m->c->floor_color[i])
	{
		if (m->c->floor_color[i] >= '0' && m->c->floor_color[i] <= '9')
		{
			r = ft_atoi(&m->c->floor_color[i]);
			while (m->c->floor_color[i] != ',')
				i++;
			if (!(m->c->floor_color[i + 1] >= '0' && m->c->floor_color[i + 1] <= '9') && m->c->floor_color[i
				+ 1] != ' ' && m->c->floor_color[i + 1] != '\t' && m->c->floor_color[i + 1] != ',')
				{
					printf("coco\n");
					return (-1);
				}
		}
		while (m->c->floor_color[i] == ' ' || m->c->floor_color[i] == '\t'
			|| m->c->floor_color[i] == ',')
			i++;
		if (m->c->floor_color[i] >= '0' && m->c->floor_color[i] <= '9')
		{
			g = ft_atoi(&m->c->floor_color[i]);
			while (m->c->floor_color[i] != ',')
				i++;
			if (!(m->c->floor_color[i + 1] >= '0' && m->c->floor_color[i + 1] <= '9') && m->c->floor_color[i
				+ 1] != ' ' && m->c->floor_color[i + 1] != '\t' && m->c->floor_color[i + 1] != ',')
				{
					printf("coco2\n");
					return (-1);
				}
		}
		while (m->c->floor_color[i] == ' ' || m->c->floor_color[i] == '\t'
			|| m->c->floor_color[i] == ',')
			i++;
		if (m->c->floor_color[i] >= '0' && m->c->floor_color[i] <= '9')
		{
			b = ft_atoi(&m->c->floor_color[i]);
			while (ft_isdigit(m->c->floor_color[i]))
				i++;
			if (m->c->floor_color[i + 1] || !white_space(m->c->floor_color[i]))
			{
					printf("coco3\n");
					return (-1);
			}
		}
		if (i == ft_strlen2(m->c->floor_color))
		{
			if (r == -1 || g == -1 || b == -1)
				return (-1);
			return ((r << 16) | (g << 8) | b);
		}
		i++;
	}
	if (r == -1 || g == -1 || b == -1)
		return (-1);
	return (0);
}
