/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 16:03:28 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/10 16:42:30 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	init(t_mlx *mlx)
{
	t_cam	*cam;

	cam = (t_cam*)malloc(sizeof(t_cam));
	mlx->add_x = 0;
	mlx->add_y = 0;
	mlx->add_z = 0.75;
	mlx->cam = cam;
	mlx->cam->alpha = 0;
	mlx->cam->beta = 0;
	mlx->cam->gamma = 0;
	mlx->cam->zoom = 10;
	mlx->iso = 0;
	if (ft_read(mlx) == -1)
	{
		ft_putendl("ERROR: INVALID MAP");
		return ;
	}
	handle(mlx);
	return ;
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
	{
		mlx.name = av[1];
		mlx.fd = open(mlx.name, O_RDONLY);
		mlx.fd != -1 ? init(&mlx) : ft_putendl("ERROR: NOT A VALID FILE");
	}
	else
		ft_putendl("usage: ./fdf [file]");
	return (0);
}
