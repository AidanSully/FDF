/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 16:05:13 by asulliva       #+#    #+#                */
/*   Updated: 2019/04/28 16:08:14 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle(t_map *map)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, map->name);
	//draw(map);
	mlx_pixel_put(mlx.mlx, mlx.win, 500, 500, 0xF44242);
	mlx_loop(mlx.mlx);
}
