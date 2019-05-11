/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 18:47:44 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/10 17:08:23 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, int z)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_var		set_delta(t_var v1, t_var v2, t_var d)
{
	d.x = abs(v2.x - v1.x);
	d.y = abs(v2.y - v1.y);
	return (d);
}

t_var		set_sigma(t_var v1, t_var v2, t_var s)
{
	if (v1.x < v2.x)
		s.x = 1;
	else
		s.x = -1;
	if (v1.y < v2.y)
		s.y = 1;
	else
		s.y = -1;
	return (s);
}

t_var		set_var(t_var v, t_mlx *mlx, int x, int y)
{
	v.x = x * mlx->cam->zoom + mlx->add_x;
	v.y = y * mlx->cam->zoom + mlx->add_y;
	v.z = (mlx->map[y][x]) * (mlx->cam->zoom / 3) * mlx->add_z;
	if (mlx->map[y][x] > 4 && mlx->map[y][x] < 10)
		v.color = 0x00FF00;
	else if (mlx->map[y][x] >= 10)
		v.color = 0xFF0000;
	else if (mlx->map[y][x] < 0)
		v.color = 0x0000FF;
	else
		v.color = 0xFFFFFF;
	return (v);
}

t_var		rotate_xyz(t_var v, t_mlx *mlx)
{
	int		x_tmp;
	int		y_tmp;

	v.y -= (mlx->size_y * mlx->cam->zoom) / 2;
	v.x -= (mlx->size_x * mlx->cam->zoom) / 2;
	x_tmp = v.x;
	y_tmp = v.y;
	v.y = y_tmp * cos(mlx->cam->alpha) - v.z * sin(mlx->cam->alpha);
	v.z = y_tmp * sin(mlx->cam->alpha) + v.z * cos(mlx->cam->alpha);
	v.x = x_tmp * cos(mlx->cam->beta) + v.z * sin(mlx->cam->beta);
	v.z = -x_tmp * sin(mlx->cam->beta) + v.z * cos(mlx->cam->beta);
	x_tmp = v.x;
	y_tmp = v.y;
	v.x = x_tmp * cos(mlx->cam->gamma) - y_tmp * sin(mlx->cam->gamma);
	v.y = x_tmp * sin(mlx->cam->gamma) + y_tmp * cos(mlx->cam->gamma);
	if (mlx->iso == 1)
		iso(&v.x, &v.y, v.z);
	v.y += (mlx->size_y * mlx->cam->zoom) / 2;
	v.x += (mlx->size_x * mlx->cam->zoom) / 2;
	return (v);
}
