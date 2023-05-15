/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:46:07 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/15 18:30:55 by mobushi          ###   ########.fr       */
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

void	plot_fractol(t_data *mlx, int flag)
{
	if (flag)
		mandelbrot(mlx);
	else
		start_mandelbrot(mlx);
}

int main (int argc, char **argv)
{
	t_data mlx;
	
	if(argc == 1)
		return(print_available_parameters());
	if(ft_strcmp(argv[1],"Mandelbrot") && argc == 2)
	{
		mlx.fractol_type = 0;
		plot_fractol(&mlx,0);
	}
	else if (ft_strcmp(argv[1],"Julia") && argc == 3)  
	{
		mlx.fractol_type = ft_atol(argv[2]);
		if(mlx.fractol_type < 0 || 100 < mlx.fractol_type)
			return(print_available_parameters());
		plot_fractol(&mlx,0);
	}
	else
		return(print_available_parameters());
	return 0;
}

__attribute__((destructor))
	static void destructor(void){
		system("leaks -q fractol");
	}