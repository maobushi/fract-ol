/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:11:52 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/15 18:16:05 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <limits.h>

# define SIZEX 1000
# define SIZEY 1000
# define MINX -1.7//-2
# define MAXX 2.3 //2
# define MINY -2 //-2
# define MAXY 2 //2
# define MAX_ITER 120

typedef struct s_data
{
	void		*mlx;
	void		*win;
	long long	fractol_type;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	int			color;
	int			loopx;
	int			loopy;
	int			fractol;
}t_data;

long long	ft_atol(const char *str);
bool		ft_strcmp(const char *s1, const char *s2);
int			ft_exit(void);
int			zoom(int keycode, int x, int y, t_data *mlx);
int			mandelbrot(t_data *mlx);
void		start_mandelbrot(t_data *mlx);
void		plot_fractol(t_data *mlx, int flag);
#endif