// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   player_images.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/08/10 17:07:46 by iszitoun          #+#    #+#             */
// /*   Updated: 2023/08/10 17:36:36 by iszitoun         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"

// void	floor_before_player(t_main *m)
// {
// 	m->xpm_img = mlx_xpm_file_to_image(m->mlx, "textures/floor.xpm", &m->w,
// 			&m->h);
// 	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
// 		* 60);
// }

// void	looking_right(t_main *m)
// {
// 	// floor_before_player(m);
// 	m->sp[m->pos_y][m->pos_x] = '0';
// 	m->pos_x++;
// 	m->sp[m->pos_y][m->pos_x] = 'N';
// 	m->xpm_img = mlx_xpm_file_to_image(m->mlx, m->p->east_path,
// 			&m->w, &m->h);
// 	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
// 		* 60);
// }

// void	looking_left(t_main *m)
// {
// 	// floor_before_player(m);
// 	m->sp[m->pos_y][m->pos_x] = '0';
// 	m->pos_x--;
// 	m->sp[m->pos_y][m->pos_x] = 'N';
// 	m->xpm_img = mlx_xpm_file_to_image(m->mlx, m->p->west_path,
// 			&m->w, &m->h);
// 	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
// 		* 60);
// }

// void	looking_up(t_main *m)
// {
// 	// floor_before_player(m);
// 	m->sp[m->pos_y][m->pos_x] = '0';
// 	m->pos_y--;
// 	m->sp[m->pos_y][m->pos_x] = 'N';
// 	m->xpm_img = mlx_xpm_file_to_image(m->mlx, m->p->north_path, &m->w,
// 			&m->h);
// 	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
// 		* 60);
// }

// void	looking_down(t_main *m)
// {
// 	// floor_before_player(m);
// 	m->sp[m->pos_y][m->pos_x] = '0';
// 	m->pos_y++;
// 	m->sp[m->pos_y][m->pos_x] = 'N';
// 	m->xpm_img = mlx_xpm_file_to_image(m->mlx, m->p->south_path, &m->w,
// 			&m->h);
// 	mlx_put_image_to_window(m->mlx, m->win, m->xpm_img, m->pos_x * 60, m->pos_y
// 		* 60);
// }
