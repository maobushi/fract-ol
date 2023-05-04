#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

#define SIZEX 700
#define SIZEY 700
#define MINX -2
#define MAXX 2
#define MINY -2
#define MAXY 2
#define MAX_ITER 30

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fractol_type;
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
	int		color;
	size_t x_pixel;
	size_t y_pixel;
}t_data;

#endif
