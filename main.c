/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 16:03:28 by asulliva       #+#    #+#                */
/*   Updated: 2019/04/28 16:10:56 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

/*
**	gcc main.c read.c mlx.c libft/libft.a -I minilibx_macos/mlx.h -L
**	minilibx_macos -lmlx -framework OpenGL -framework AppKit
*/

void	init(t_map *map)
{
	if (ft_read(map) == -1)
	{
		ft_putendl("ERROR: INVALID MAP");
		return ;
	}
	handle(map);
	return ;
}

int		main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		map.name = av[1];
		map.fd = open(map.name, O_RDONLY);
		init(&map);
	}
	else
		ft_putendl("usage: ./fdf [file]");
	return (0);
}
