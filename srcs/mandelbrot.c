/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:21:36 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/19 17:35:12 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	put_pixel_window(t_data*mlx, double x, double y, int flag)
{
	if (mlx->fractol_type == 0 && flag == 0)
		return (0);
	else if (mlx->fractol_type == 0 && flag == 1)
		return (0);
	else if (mlx->fractol_type == 0 && flag == 2)
		return (x);
	else if (mlx->fractol_type == 0 && flag == 3)
		return (y);
	else if (mlx->fractol_type != 0 && flag == 0)
		return (x);
	else if (mlx->fractol_type != 0 && flag == 1)
		return (y);
	else if (mlx->fractol_type != 0 && flag == 2)
		return (0);
	else if (mlx->fractol_type != 0 && flag == 3)
		return (0);
	return (0);
}

int	mandelbrot_set(double x, double y, t_data *mlx)
{
	int		i;

	mlx->real = put_pixel_window(mlx, x, y, 0);
	mlx->imag = put_pixel_window(mlx, x, y, 1);
	x = put_pixel_window(mlx, x, y, 2);
	y = put_pixel_window(mlx, x, y, 3);
	i = 1;
	while (i < MAX_ITER)
	{
		mlx->tmp = mlx->real;
		mlx->real = ((mlx->real * mlx->real) - (mlx->imag * mlx->imag)) + x;
		mlx->imag = (2 * mlx->tmp * mlx->imag) + y;
		mlx->real += (((double)mlx->fractol_type) / 1000) * -1;
		mlx->imag += ((double)mlx->fractol_type) / 1000;
		if ((mlx->real * mlx->real) + (mlx->imag * mlx->imag) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy, CLR * i);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy, 0x000E0E0E);
	return (0);
}

int	mandelbrot(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = (double)mlx->xmin + ((double)mlx->loopx * (((double)mlx->xmax
							- (double)mlx->xmin) / (double)SIZEX));
			y = (double)mlx->ymax - ((double)mlx->loopy * (((double)mlx->ymax
							- (double)mlx->ymin) / (double)SIZEY));
			mandelbrot_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (1);
}

void	start_mandelbrot(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SIZEX, SIZEY, "Fract'ol");
	mlx->xmin = MINX;
	mlx->xmax = MAXX;
	mlx->ymin = MINY;
	mlx->ymax = MAXY;
	mlx->color = 0;
	mlx->fractol = 1;
	mandelbrot((void *)mlx);
	mlx_hook(mlx->win, 17, 2, ft_exit, (void *)0);
	mlx_key_hook(mlx->win, ft_exit_esc, mlx);
	mlx_mouse_hook(mlx->win, zoom, mlx);
	mlx_loop(mlx->mlx);
}
