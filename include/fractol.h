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
#define MAX_ITER 120

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
	int		loopx;
	int		loopy;
	int 	fractol;
	size_t x_pixel;
	size_t y_pixel;
}t_data;


bool	ft_strcmp(const char *s1, const char *s2);
int	ft_exit(void);
int	zoom(int keycode, int x, int y, t_data *mlx);
int	mandelbrot(t_data *mlx);
void	start_mandelbrot(void);
void    plot_fractol(t_data *mlx, int flag);

#endif
