/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:20:40 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/15 17:59:30 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long long	ft_atol(const char *str)
{
	long long	ln;
	size_t		n;
	int			sign;

	sign = 1;
	ln = 0;
	n = 0;
	while (str[n] == 32 || (9 <= str[n] && str[n] <= 13))
		n++;
	if (str[n] == '-')
		sign *= -1;
	if (str[n] == '+' || str[n] == '-')
		n++;
	while ('0' <= str[n] && str[n] <= '9')
	{
		if (ln != ((ln * 10) + (str[n] - '0') * sign) / 10 && sign > 0)
			return ((int)LONG_MAX);
		if (ln != ((ln * 10) + (str[n] - '0') * sign) / 10 && sign < 0)
			return ((int)LONG_MIN);
		ln = (ln * 10) + (str[n] - '0') * sign;
		n++;
	}
	return (ln);
}

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
	(void)x;
	(void)y;
	double x_tmp;
	double y_tmp;

	x_tmp = mlx->xmax - mlx->xmin;
	y_tmp = mlx->ymax - mlx->ymin;
	if (keycode == 5)//zoom
	{
		mlx->xmin += (x_tmp)*0.25;
		mlx->xmax -= (x_tmp)*0.25;
		mlx->ymax -= (y_tmp)*0.25;
		mlx->ymin += (y_tmp)*0.25;
	}
	if (keycode == 4)//out
	{
		mlx->xmin -= ((x_tmp)*0.5);
		mlx->xmax += ((x_tmp)*0.5);
		mlx->ymax += ((y_tmp)*0.5);
		mlx->ymin -= ((y_tmp)*0.5);
	}
	plot_fractol(mlx, 1);
	return (0);
}
