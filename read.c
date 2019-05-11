/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 16:05:31 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/10 18:05:34 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		get_xy(t_mlx *map, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (map->size_y == 0)
		map->size_x = i;
	else
	{
		if (i != map->size_x)
			return (-1);
	}
	free(line);
	free(tab);
	map->size_y++;
	return (0);
}

int		get_input(t_mlx *map)
{
	char	*line;
	int		ret;

	line = NULL;
	map->size_x = 0;
	map->size_y = 0;
	while ((ret = get_next_line(map->fd, &line)))
	{
		if (get_xy(map, line) == -1)
			return (-1);
	}
	map->map = malloc(sizeof(int*) * map->size_y);
	close(map->fd);
	free(line);
	map->fd = open(map->name, O_RDONLY);
	return (0);
}

/*
**	i[0] = x
**	i[1] = y
**	i[2] = ret
*/

int		ft_read(t_mlx *map)
{
	char	*line;
	char	**tab;
	int		i[3];

	i[1] = 0;
	if (get_input(map) == -1)
		return (-1);
	while ((i[2] = get_next_line(map->fd, &line)))
	{
		i[0] = 0;
		tab = ft_strsplit(line, ' ');
		map->map[i[1]] = ft_memalloc(sizeof(int) * map->size_x);
		while (tab[i[0]] != NULL)
		{
			map->map[i[1]][i[0]] = ft_atoi(tab[i[0]]);
			free(tab[i[0]]);
			i[0]++;
		}
		free(tab);
		free(line);
		i[1]++;
	}
	free(line);
	return (i[2]);
}
