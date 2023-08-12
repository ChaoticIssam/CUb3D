/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:18:00 by iszitoun          #+#    #+#             */
/*   Updated: 2023/08/10 13:41:52 by iszitoun         ###   ########.fr       */
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
	if (!m->str)
		return (0);
	create_map(m);
	items_check(m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 1000 * 6, 1000 * 6, "CUB3D");
	mlx_loop_hook(m->mlx, put_image, m);
	mlx_hook(m->win, 2, 0, &moving_key, m);
	mlx_hook(m->win, 17, 0, quit, m);
	mlx_loop(m->mlx);
}