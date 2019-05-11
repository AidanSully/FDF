/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 15:06:00 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/09 19:03:40 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

int		win_width(t_mlx *map)
{
	int		w;

	w = map->size_x * 30 + 150;
	if (w > 2500)
		w = 2500;
	return (w);
}

int		win_height(t_mlx *map)
{
	int		h;

	h = map->size_y * 30 + 150;
	if (h > 1500)
		h = 1500;
	return (h);
}
