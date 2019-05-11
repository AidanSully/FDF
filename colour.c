/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 17:23:43 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/10 17:35:29 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_var cur, t_var v1, t_var v2, t_var d)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (cur.color == v2.color)
		return (cur.color);
	if (d.x > d.y)
		percentage = percent(v1.x, v2.x, cur.x);
	else
		percentage = percent(v1.y, v2.y, cur.y);
	r = get_light((v1.color >> 16) & 0xFF, (v2.color >> 16) & 0xFF, percentage);
	g = get_light((v1.color >> 8) & 0xFF, (v2.color >> 8) & 0xFF, percentage);
	b = get_light((v1.color) & 0xFF, (v2.color) & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
