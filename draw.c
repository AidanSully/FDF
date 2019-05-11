/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 16:11:11 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/10 18:10:15 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	int i;

	if (x > 0 && x < win_width(mlx) && y > 0 && y < win_height(mlx))
	{
		i = (x * mlx->bits_in_pixel / 8) + (y * mlx->size_line);
		mlx->data_address[i] = color;
		mlx->data_address[i + 1] = color >> 8;
		mlx->data_address[i + 2] = color >> 16;
	}
}

void		draw_line(t_mlx *mlx, t_var v1, t_var v2)
{
	t_var	d;
	t_var	s;
	t_var	cur;
	int		i[2];

	d = set_delta(v1, v2, v1);
	s = set_sigma(v1, v2, v2);
	i[0] = d.x - d.y;
	cur = v1;
	while (cur.x != v2.x || cur.y != v2.y)
	{
		pixel_to_image(mlx, cur.x + mlx->startx, cur.y + mlx->starty,
										get_color(cur, v1, v2, d));
		i[1] = i[0] * 2;
		if (i[1] > -d.y)
		{
			i[0] -= d.y;
			cur.x += s.x;
		}
		if (i[1] < d.x)
		{
			i[0] += d.x;
			cur.y += s.y;
		}
	}
}

void		draw_map_x(t_mlx *mlx, int x, int y)
{
	t_var	v1;
	t_var	v2;

	while (x < mlx->size_x)
	{
		v1 = set_var(v1, mlx, x, y);
		v1 = rotate_xyz(v1, mlx);
		if (x + 1 < mlx->size_x)
		{
			v2 = set_var(v2, mlx, x + 1, y);
			v2 = rotate_xyz(v2, mlx);
			draw_line(mlx, v1, v2);
		}
		if (y + 1 < mlx->size_y)
		{
			v2 = set_var(v2, mlx, x, y + 1);
			v2 = rotate_xyz(v2, mlx);
			draw_line(mlx, v1, v2);
		}
		x++;
	}
}

void		draw_map(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	ft_bzero(mlx->data_address, (win_height(mlx) * win_width(mlx)) *
	(mlx->bits_in_pixel / 8));
	mlx->startx = ((win_width(mlx) - (mlx->size_x * mlx->cam->zoom)) / 2);
	mlx->starty = ((win_height(mlx) - (mlx->size_y * mlx->cam->zoom)) / 2);
	while (y < mlx->size_y)
	{
		x = 0;
		draw_map_x(mlx, x, y);
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	help_display(mlx, 0xFFFFFF);
	return ;
}
