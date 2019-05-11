/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 16:17:47 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/10 17:35:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_ESC 53
# define KEY_MINUS 27
# define KEY_PLUS 24
# define D_ARR 125
# define U_ARR 126
# define L_ARR 123
# define R_ARR 124
# define M_CLICK 1
# define SCR_UP 4
# define SCR_DWN 5
# define L_SQUARE 33
# define R_SQUARE 30
# define SPACE 49

# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_cam
{
	double			alpha;
	double			beta;
	double			gamma;
	double			zoom;
}					t_cam;

typedef struct		s_var
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_var;

typedef struct		s_mlx
{
	int				fd;
	void			*mlx;
	void			*win;
	char			*name;
	int				size_x;
	int				size_y;
	int				**map;
	void			*img;
	char			*data_address;
	int				endian;
	int				size_line;
	int				bits_in_pixel;
	int				add_x;
	int				add_y;
	double			add_z;
	int				startx;
	int				starty;
	int				iso;
	t_cam			*cam;
}					t_mlx;

void				handle(t_mlx *map);
int					get_xy(t_mlx *map, char *line);
int					ft_read(t_mlx *map);
int					get_input(t_mlx *map);
int					win_width(t_mlx *map);
int					win_height(t_mlx *map);
void				draw_map(t_mlx *mlx);
int					get_color(t_var cur, t_var v1, t_var v2, t_var d);
void				help_display(t_mlx *mlx, unsigned c);
t_var				set_delta(t_var v1, t_var v2, t_var d);
t_var				set_sigma(t_var v1, t_var v2, t_var s);
t_var				set_var(t_var v, t_mlx *mlx, int x, int y);
t_var				rotate_xyz(t_var v, t_mlx *mlx);

#endif
