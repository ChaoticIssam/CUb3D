/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deimos <deimos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:18:20 by iszitoun          #+#    #+#             */
/*   Updated: 2023/09/03 23:33:08 by deimos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_dir
{
	int			i;
	int			j;
	int			n;
	int			s;
	int			w;
	int			e;
}				t_dir;

typedef struct s_paths
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	int			count_paths;
}				t_paths;

typedef struct s_colors
{
	char		*floor_color;
	char		*ceiling_color;
	int			count_rgb;
}				t_colors;

typedef struct s_main
{
	int			count;
	int			fd;
	char		*str;
	char		**sp;
	char		**map;
	char		**map2;
	void		*mlx;
	void		*win;
	void		*xpm_img;
	int			pos_y;
	int			pos_x;
	int			i;
	int			j;
	int			w;
	int			h;
	t_paths		*p;
	t_colors	*c;
}				t_main;

void			check_name(char *name);
void			new_line_inside(t_main *m);
int				map_frst_line(t_main *m);
void			check_check(t_main *m);

char			*ft_read_str(int fd, char *str);
char			*ft_strjoin1(char *left_str, char *buff);

void			create_map(t_main *m);

char			*dir_path(t_main *m);
void			items_check(t_main *m);
int				line_count(t_main *m);
int				line_len(char *s);
int				map_check_first(t_main *m);
int				map_check_last(t_main *m);

void			invalid_item(t_main *m);
int				p_check(t_main *m);

void			put_floor(t_main *m);
int				put_image(t_main *m);

void			invalid_item_error(void);
void			arg_error(void);
void			sides_error(void);
void			horinzontal_error(void);
void			duplicated_player_error(void);
void			path_error(void);
void			void_next_floor(void);
void			color_error(void);
void			undefined_line_error(void);
void			empty_line_inside(void);

int				moving_key(int keysym, t_main *m);
void			right_key(t_main *m);
void			left_key(t_main *m);
void			down_key(t_main *m);
void			up_key(t_main *m);

void			for_north(t_main *m, t_dir *dir);
void			for_south(t_main *m, t_dir *dir);
void			for_west(t_main *m, t_dir *dir);
void			for_east(t_main *m, t_dir *dir);

void			check_sides(t_main *m);
int				white_space(char c);
void			around_floor(t_main *m);
void			line_undef(t_main *m);

void			floor_before_player(t_main *m);
void			looking_right(t_main *m);
void			looking_left(t_main *m);
void			looking_up(t_main *m);
void			looking_down(t_main *m);

char			*floor_ceiling(t_main *m);
int				merge_floor_color(t_main *m);
int				merge_ceiling_color(t_main *m);

#endif