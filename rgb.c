/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:03:19 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/06 20:53:01 by deimos           ###   ########.fr       */
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

char *floor_color_final(char *str)
{
	int	i;
	int	j;
	int	count;
	int	count1;
	int	lock;
	char *floor;

	floor = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	j = 0;
	lock = 0;
	count = 0;
	count1 = 0;
	while (str[i])
	{
		lock = 0;
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t' && str[i] != ',')
			return (NULL);
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (ft_isdigit(str[i]))
		{
			if (lock == 0)
			{
				count++;
				lock = 1;
			}
			floor[j] = str[i];
			i++;
			j++;
		}
		if (str[i] == ',' || str[i] == ' ' || str[i] == '\t')
		{
			if (str[i] == ',')
				count1++;
			floor[j] = str[i];
			i++;
			j++;
		}
	}
	if (count != 3 || count1 != 2)
		return (NULL);
	floor[j] = '\0';
	return (floor);
}

char *ceiling_color_final(char *str)
{
	int	i;
	int	j;
	int	count;
	int	count1;
	int	lock;
	char *ceiling;

	ceiling = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	j = 0;
	lock = 0;
	count = 0;
	count1 = 0;
	while (str[i])
	{
		lock = 0;
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t' && str[i] != ',')
			return (NULL);
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (ft_isdigit(str[i]))
		{
			if (lock == 0)
			{
				count++;
				lock = 1;
			}
			ceiling[j] = str[i];
			i++;
			j++;
		}
		if (str[i] == ',' || str[i] == ' ' || str[i] == '\t')
		{
			if (str[i] == ',')
				count1++;
			ceiling[j] = str[i];
			i++;
			j++;
		}
	}
	if (count != 3 || count1 != 2)
		return (NULL);
	ceiling[j] = '\0';
	return (ceiling);
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
	m->c->floor_color = floor_color_final(m->c->floor_color);
	if (m->c->floor_color == NULL)
		return(-1);
	while (m->c->floor_color[i])
	{
		if (m->c->floor_color[i] >= '0' && m->c->floor_color[i] <= '9')
		{
			r = ft_atoi(&m->c->floor_color[i]);
			while (m->c->floor_color[i] != ',')
				i++;
			if (!(m->c->floor_color[i + 1] >= '0' && m->c->floor_color[i + 1] <= '9') && m->c->floor_color[i
				+ 1] != ' ' && m->c->floor_color[i + 1] != '\t' && m->c->floor_color[i + 1] != ',')
					return (-1);
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
					return (-1);
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
					return (-1);
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

int	merge_ceiling_color(t_main *m)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	r = -1;
	g = -1;
	b = -1;
	m->c->ceiling_color = ceiling_color_final(m->c->ceiling_color);
	if (!m->c->ceiling_color)
		return (-1);
	while (m->c->ceiling_color[i])
	{
		if (m->c->ceiling_color[i] >= '0' && m->c->ceiling_color[i] <= '9')
		{
			r = ft_atoi(&m->c->ceiling_color[i]);
			while (m->c->ceiling_color[i] != ',')
				i++;
			if (!(m->c->ceiling_color[i + 1] >= '0' && m->c->ceiling_color[i + 1] <= '9') && m->c->ceiling_color[i
				+ 1] != ' ' && m->c->ceiling_color[i + 1] != '\t' && m->c->ceiling_color[i + 1] != ',')
				return (-1);
		}
		while (m->c->ceiling_color[i] == ' ' || m->c->ceiling_color[i] == '\t'
			|| m->c->ceiling_color[i] == ',')
			i++;
		if (m->c->ceiling_color[i] >= '0' && m->c->ceiling_color[i] <= '9')
		{
			g = ft_atoi(&m->c->ceiling_color[i]);
			while (m->c->ceiling_color[i] != ',')
				i++;
			if (!(m->c->ceiling_color[i + 1] >= '0' && m->c->ceiling_color[i + 1] <= '9') && m->c->ceiling_color[i
				+ 1] != ' ' && m->c->ceiling_color[i + 1] != '\t' && m->c->ceiling_color[i + 1] != ',')
					return (-1);
		}
		while (m->c->ceiling_color[i] == ' ' || m->c->ceiling_color[i] == '\t'
			|| m->c->ceiling_color[i] == ',')
			i++;
		if (m->c->ceiling_color[i] >= '0' && m->c->ceiling_color[i] <= '9')
		{
			b = ft_atoi(&m->c->ceiling_color[i]);
			while (ft_isdigit(m->c->ceiling_color[i]))
				i++;
			if (m->c->ceiling_color[i + 1] || !white_space(m->c->ceiling_color[i]))
					return (-1);
		}
		if (i == ft_strlen2(m->c->ceiling_color))
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
