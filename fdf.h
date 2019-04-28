#ifndef FDF_H
# define FDF_H

# define WIDTH 1024
# define HEIGHT 768
# define STARTX WIDTH / 2
# define STARTY HEIGHT / 2

# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct		s_map
{
	int				fd;
	char			*name;
	int				**map;
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	void			*mlx;
	void			*win;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;


void    			handle(t_map *map);

/*
**	Reader functions
*/

int					get_xy(t_map *map, char *line);
int					ft_read(t_map *map);
int					get_input(t_map *map);

#endif
