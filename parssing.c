/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:22:38 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/24 18:14:16 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	where_to_stop(t_main *m)
{
	int	i;

	i = 0;
	while (m->str[i])
	{
		if (m->str[i] == '\n')
		{
			while (white_space(m->str[i]))
				i++;
			if (m->str[i] == '1')
				return (i);
		}
		i++;
	}
	return (0);
}

void	new_line_inside(t_main *m)
{
	int	i;
	int	last;

	i = ft_strlen(m->str);
	last = where_to_stop(m);
	while (i >= last)
	{
		if (m->str[i] == '\n' && m->str[i - 1] == '\n')
			empty_line_inside();
		i--;
	}
}

int	map_first_line(t_main *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'C')
				return(i);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_frst_line(t_main *m)
{
	int	i;
	int	j;

	i = map_first_line(m) + 1;
	j = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j] && (m->map[i][j] == ' ' || m->map[i][j] == '\t'))
			j++;
		if (m->map[i][j] == '1' || m->map[i][j] == 32 || m->map[i][j] == '\t')
		{
			while ((m->map[i][j] == '1' || m->map[i][j] == 32 || m->map[i][j] == '\t') && m->map[i][j])
			{
				j++;
				if (!m->map[i][j] || m->map[i][j] == '\n')
					return (i);
			}
			horinzontal_error();
		}
		i++;
	}
	return (0);
}

void	check_check(t_main *m)
{
	if (m->fd == -1)
	{
		perror("error");
		exit(1);
	}
	m->str = NULL;
	m->str = ft_read_str(m->fd, m->str);
}

void	check_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (ft_strncmp(&name[i], ".cub") != 0)
		arg_error();
}
