/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:01:20 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/06 20:54:41 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_floor(t_main *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "textures/floor.xpm", &m->w,
			&m->h);
	if (m->xpm_img == NULL)
		exit(1);
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}

void	put_walls(t_main *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "textures/wall.xpm", &m->w,
			&m->h);
	if (m->xpm_img == NULL)
	{
		printf("wall\n");
		exit(1);
	}
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}

void	put_player_north(t_main *m)
{
	m->xpm_img = mlx_xpm_file_to_image(m->mlx, m->p->north_path, &m->w, &m->h);
	if (!m->xpm_img)
	{
		printf("hello\n");
		exit(1);
	}
	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->j * 60, m->i * 60);
}

int	put_image(t_main *m)
{
	m->i = map_frst_line(m);
	while (m->sp[m->i])
	{
		m->j = 0;
		
		while (m->sp[m->i][m->j])
		{
			// if (m->sp[m->i][m->j] != ' ')
			// 	put_floor(m);
			if (m->sp[m->i][m->j] == '1')
				put_walls(m);
				if (m->sp[m->i][m->j] == 'N' || m->sp[m->i][m->j] == 'S'
					|| m->sp[m->i][m->j] == 'E' || m->sp[m->i][m->j] == 'W')
					put_player_north(m);
			m->j++;
		}
		m->i++;
	}
	return (0);
}