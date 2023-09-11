/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:22:38 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/09 01:27:15 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		printf("line is ->>>>%s and char is ->>>%c\n", m->map[i], m->map[i][j]);
		while (m->map[i][j] && (m->map[i][j] == ' ' || m->map[i][j] == '\t'))
			j++;
		if (m->map[i][j] == '1')
		{
			while ((m->map[i][j] == '1') && m->map[i][j])
			{
				j++;
				if (!m->map[i][j] || m->map[i][j] == '\n')
					return (i);
			}
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
