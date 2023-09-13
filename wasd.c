// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   wasd.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/08/07 10:15:07 by iszitoun          #+#    #+#             */
// /*   Updated: 2023/08/10 17:50:10 by iszitoun         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"

// int	moving_key(int keysym, t_main *m)
// {
// 	m->count = 0;
// 	if (keysym == 2 || keysym == 124)
// 		right_key(m);
// 	if (keysym == 0 || keysym == 123)
// 		left_key(m);
// 	if (keysym == 13 || keysym == 126)
// 		up_key(m);
// 	if (keysym == 1 || keysym == 125)
// 		down_key(m);
// 	if (keysym == 53)
// 	{
// 		ft_printf("\033[0;31m\n\t-->|You exited the game|<--\n\n");
// 		exit(0);
// 	}
// 	return (0);
// }

// void	right_key(t_main *m)
// {
// 	if (m->sp[m->pos_y][m->pos_x + 1] == '0')
// 		looking_right(m);
// 	return ;
// }

// void	left_key(t_main *m)
// {
// 	if (m->sp[m->pos_y][m->pos_x - 1] == '0')
// 		looking_left(m);
// 	return ;
// }

// void	down_key(t_main *m)
// {
// 	if (m->sp[m->pos_y + 1][m->pos_x] == '0')
// 		looking_down(m);
// 	return ;
// }

// void	up_key(t_main *m)
// {
// 	if (m->sp[m->pos_y - 1][m->pos_x] == '0')
// 		looking_up(m);
// 	return ;
// }

