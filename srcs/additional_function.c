/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:20:40 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/14 20:21:13 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(void)
{
	exit(1);
	return (0);
}


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

int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->xmax - mlx->xmin) / SIZEX;
	dy = (mlx->ymax - mlx->ymin) / SIZEY;
	if (keycode == 5)
	{
		mlx->xmin = (mlx->xmin + ((dx * x) * 0.5));
		mlx->xmax = (mlx->xmax - ((dx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax - ((dy * y) * 0.5));
		mlx->ymin = (mlx->ymin + ((dy * (SIZEY - y)) * 0.5));
	}
	if (keycode == 4)
	{
		mlx->xmin = (mlx->xmin - ((dx * x) * 0.5));
		mlx->xmax = (mlx->xmax + ((dx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax + ((dy * y) * 0.5));
		mlx->ymin = (mlx->ymin - ((dy * (SIZEY - y)) * 0.5));
	}
	plot_fractol(mlx, 1);
	return (0);
}
