/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:46:07 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/14 22:57:07 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int print_available_parameters()
{
	printf("input error!\n");
	printf("available input is:\n");
	printf("1. Mandelbrot\n");
	printf("2. Julia\n");
	return(1);
}
//preproccess end

void	plot_fractol(t_data *mlx, int flag)
{
	if (flag)
		mandelbrot(mlx);
	else
		start_mandelbrot();
}

int main (int argc, char **argv)
{
	t_data mlx;

	if(ft_strcmp(argv[1],"Mandelbrot") && argc == 2)
	{
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