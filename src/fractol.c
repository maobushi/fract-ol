/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:46:07 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/04 14:35:23 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


bool	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}

int print_available_parameters()
{
	printf("input error!\n");
	printf("available input is:\n");
	printf("1. Mandelbrot\n");
	printf("2. Julia\n");
	return(1);
}

int	zoom(int keycode,t_data *mlx)
{
	double	dx;
	double	dy;

	dx = (mlx->xmax - mlx->xmin) / SIZEX;
	dy = (mlx->ymax - mlx->ymin) / SIZEY;
	if (keycode == 5)
	{
		mlx->xmin = (mlx->xmin + ((dx * mlx->xmin + mlx->xmax /2) * 0.5));
		mlx->xmax = (mlx->xmax - ((dx * (SIZEX - mlx->xmin + mlx->xmax /2)) * 0.5));
		mlx->ymax = (mlx->ymax - ((dy * mlx->ymin + mlx->ymax /2) * 0.5));
		mlx->ymin = (mlx->ymin + ((dy * (SIZEY - mlx->ymin + mlx->ymax /2)) * 0.5));
	}
	if (keycode == 4)
	{
		mlx->xmin = (mlx->xmin - ((dx * mlx->xmin + mlx->xmax /2) * 0.5));
		mlx->xmax = (mlx->xmax + ((dx * (SIZEX - mlx->xmin + mlx->xmax /2)) * 0.5));
		mlx->ymax = (mlx->ymax + ((dy * mlx->ymin + mlx->ymax /2) * 0.5));
		mlx->ymin = (mlx->ymin - ((dy * (SIZEY - mlx->ymin + mlx->ymax /2)) * 0.5));
	}
	return (0);
}
int	ft_close(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(1);
	return (1);
}

void plot_mandelbrot(size_t x,size_t y,t_data *mlx)
{
	size_t i;
	double real_num;
	double imaginary_num;
	double tmp;

	i=1;
	while(i < MAX_ITER)
	{
		tmp = real_num;
		real_num = real_num*real_num  - imaginary_num*imaginary_num + x;
		imaginary_num = 2*tmp*imaginary_num+y;

		if(real_num * real_num + imaginary_num*imaginary_num > 4)
		{
				mlx_pixel_put(mlx->mlx, mlx->win, mlx->x_pixel, mlx->y_pixel,
				(mlx->color) + 0x008DE3EC * i);//4bitづつ指定可能、 mlxは255 255 255でTRGB 試行回数が多いほど濃くなるようにset
			return ;
		}
		i++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->x_pixel, mlx->y_pixel,
				(mlx->color) + 0x008DE3EC * i);//4bitづつ指定可能、 mlxは255 255 255でTRGB 試行回数が多いほど濃くなるようにset
	return;
}

void plot_coordinates(t_data* mlx)
{
	mlx->x_pixel = 0;
	mlx->y_pixel = 0;
	double x = 0;
	double y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while(mlx->x_pixel < SIZEX)
	{
		mlx->y_pixel = 0;
		while(mlx->y_pixel < SIZEY)
		{
			x = mlx->xmin + (mlx->x_pixel * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymin + (mlx->y_pixel * ((mlx->ymax - mlx->ymin) / SIZEY));
			mlx->y_pixel++;
			plot_mandelbrot(x,y,mlx);
		}
		mlx->x_pixel++;
	}
	return;
}

void plot_fractol(t_data* mlx,size_t flag)
{
	if(flag == 0)
	{
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, SIZEX, SIZEY, "Fract'ol");
		mlx->xmin = MINX;//mandelbrotのxmin(座標の指定,-2がbest)
		mlx->xmax = MAXX;//mandelbrotのxmax(座標の指定,2がbest)
		mlx->ymin = MINY;//座標の指定,-2がbest);
		mlx->ymax = MAXY;//座標の指定,2がbest);
		mlx->color = 0;
	}
	plot_coordinates(mlx);
	
	//mlx_key_hook(mlx->win, keys, (void *)&mlx);
	mlx_mouse_hook(mlx->win, zoom, (void *)&mlx);
	mlx_hook(mlx->win, 17, 2, ft_close, (void *)0);
	mlx_loop(mlx->mlx);
}

int main (int argc, char **argv)
{
	//printf("argc = %d\n",argc);
	//printf("argv[1] = %s\n",argv[1]);
	//printf("argv[2] = %s\n",argv[2]);
	t_data mlx;

	if(ft_strcmp(argv[1],"Mandelbrot") && argc == 2)
	{
		printf("hi");
		mlx.fractol_type = 0;
		 plot_fractol(&mlx,0);
	}
	 else if (ft_strcmp(argv[1],"Julia") && argc == 3)  
	{
		mlx.fractol_type = 1;
		 plot_fractol(&mlx,0);
	}
	else
		 return(print_available_parameters());
	return 0;
}