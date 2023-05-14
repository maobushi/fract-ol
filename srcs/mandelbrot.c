/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:21:36 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/14 22:56:37 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	mandelbrot_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;


	//Mandelbrot
	//xx = 0;
	//yy = 0;

	//Julia
	xx = x;
	yy = y;
	
	
	i = 1;
	while (i < 120)
	{
		temp = xx;
		xx = ((xx * xx) - (yy * yy)) + x;
		yy = (2 * temp * yy) + y;
		if ((xx * xx) + (yy * yy) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy,
				(mlx->color) + 0x008DE3EC * i);
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
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			mandelbrot_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (1);
}


void	start_mandelbrot(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, SIZEX, SIZEY, "Fract'ol");
	mlx.xmin = MINX;
	mlx.xmax = MAXX;
	mlx.ymin = MINY;
	mlx.ymax = MAXY;
	mlx.color = 0;
	mlx.fractol = 1;
	mandelbrot((void *)&mlx);
	mlx_hook(mlx.win, 17, 2, ft_exit, (void *)0);
	mlx_mouse_hook(mlx.win, zoom, (void *)&mlx);
	mlx_loop(mlx.mlx);
}
