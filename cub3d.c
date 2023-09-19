/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:18:00 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/05 16:37:25 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit(void)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_main *m;
	
	(void)ac;
	if (ac <= 1)
		exit(1);
	check_name(av[1]);
	m = malloc(sizeof(t_main));
	m->count = 1;
	m->fd = open(av[1], O_RDWR);
	check_check(m);
	new_line_inside(m);
	if (!m->str)
		return (0);
	create_map(m);
	items_check(m);
	// m->mlx = mlx_init();
	// m->win = mlx_new_window(m->mlx, 1000, 1000, "CUB3D");
	// mlx_loop_hook(m->mlx, put_image, m);
	// mlx_hook(m->win, 2, 0, &moving_key, m);
	// mlx_hook(m->win, 17, 0, quit, m);
	// mlx_loop(m->mlx);
}