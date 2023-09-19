/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:37:38 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/08 18:42:02 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horinzontal_error(void)
{
	ft_printf("ERROR:\n Check your map's Horizantal Walls!\n");
	exit(1);
}

void	arg_error(void)
{
	ft_printf("ERROR:\n The second argument should be ****.cub!\n");
	exit(1);
}

void	invalid_item_error(void)
{
	ft_printf("ERROR:\n You entered an Invalid symbole in your map!\n");
	exit(1);
}

void	duplicated_player_error(void)
{
	ft_printf("ERROR:\n Player's symbole (duplicated or missing)!\n");
	exit(1);
}

void	void_next_floor(void)
{
	ft_printf("ERROR:\n Void inside the map!\n");
	exit(1);
}

void	sides_error(void)
{
	ft_printf("\nERROR: Check your map's *VERTICAL WALLS* !!!\n");
	exit(1);
}

void	path_error(void)
{
	ft_printf("ERROR:\n \tPath is invalid or Missing!\n");
	exit(1);
}

void	color_error(void)
{
	ft_printf("ERROR:\n \tColor is invalid or Missing!\n");
	exit (1);
}

void	empty_line_inside(void)
{
	ft_printf("ERROR:\n \tEmpty line inside map!\n");
	exit (1);
}

void	undefined_line_error(void)
{
	ft_printf("ERROR:\n \tUndefined line on map file!\n");
	exit (1);
}
