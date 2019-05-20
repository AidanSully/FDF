/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/28 16:05:13 by asulliva       #+#    #+#                */
/*   Updated: 2019/05/10 17:20:11 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		help_display(t_mlx *mlx, unsigned c)
{
	short	x;

	x = 0;
	mlx_string_put(mlx->mlx, mlx->win, x, x, c, "Map:");
	mlx_string_put(mlx->mlx, mlx->win, x + 46, x, c, mlx->name);
	mlx_string_put(mlx->mlx, mlx->win, x, x + 40, c, "Controls:");
	mlx_string_put(mlx->mlx, mlx->win, x, x + 60, c, "Rotate: [W][A]\
	[S][D][Q][E]");
	mlx_string_put(mlx->mlx, mlx->win, x, x + 80, c, "Tranlate: Arrow Keys");
	mlx_string_put(mlx->mlx, mlx->win, x, x + 100, c, "Depth: [9]/[0]");
	mlx_string_put(mlx->mlx, mlx->win, x, x + 120, c, "Zoom: [=]/[-]");
	mlx_string_put(mlx->mlx, mlx->win, x, x + 140, c, "Projection: Spacebar");
}

static void	reset(t_mlx *mlx)
{
	mlx->cam->alpha = 0;
	mlx->cam->beta = 0;
	mlx->cam->gamma = 0;
	mlx->cam->zoom = 10;
	mlx->add_x = 0;
	mlx->add_y = 0;
	mlx->add_z = 0.75;
}

static int	fdf_keys1(int keycode, t_mlx *mlx)
{
	if (keycode == D_ARR)
		mlx->add_y += mlx->starty / 10;
	if (keycode == L_ARR)
		mlx->add_x -= mlx->startx / 10;
	if (keycode == R_ARR)
		mlx->add_x += mlx->startx / 10;
	if (keycode == KEY_MINUS && mlx->cam->zoom > 0)
		mlx->cam->zoom *= 0.9;
	if (keycode == KEY_PLUS)
		mlx->cam->zoom += 1.1;
	if (keycode == 25)
		mlx->add_z -= 0.25;
	if (keycode == 29)
		mlx->add_z += 0.25;
	if (keycode == SPACE)
		mlx->iso = (mlx->iso == 1 ? 0 : 1);
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_map(mlx);
	return (0);
}

static int	fdf_keys(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_S)
		mlx->cam->alpha += (0.2617993878 / 4);
	if (keycode == KEY_W)
		mlx->cam->alpha -= (0.2617993878 / 4);
	if (keycode == KEY_A)
		mlx->cam->beta -= (0.2617993878 / 4);
	if (keycode == KEY_D)
		mlx->cam->beta += (0.2617993878 / 4);
	if (keycode == KEY_R)
		reset(mlx);
	if (keycode == KEY_Q)
		mlx->cam->gamma += (0.2617993878 / 4);
	if (keycode == KEY_E)
		mlx->cam->gamma -= (0.2617993878 / 4);
	if (keycode == U_ARR)
		mlx->add_y -= mlx->starty / 10;
	return (fdf_keys1(keycode, mlx));
}

void		handle(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, win_width(mlx), win_height(mlx),
	mlx->name);
	mlx->img = mlx_new_image(mlx->mlx, win_width(mlx), win_height(mlx));
	mlx->data_address = mlx_get_data_addr(mlx->img, &mlx->bits_in_pixel,
	&mlx->size_line, &mlx->endian);
	draw_map(mlx);
	mlx_hook(mlx->win, 2, 3, fdf_keys, mlx);
	mlx_loop(mlx->mlx);
}
