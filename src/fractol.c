/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:46:07 by mobushi           #+#    #+#             */
/*   Updated: 2023/05/04 03:15:11 by mobushi          ###   ########.fr       */
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

int plot_mandelbrot(void)
{
	printf("mandelbrot!");
	return 0;	
}

int plot_julia(void)
{
	printf("Julia!");
	return 0;
}

int main (int argc, char **argv)
{
	if(ft_strcmp(argv[1],"Mandelbrot") && argc == 1)
		printf
		// plot_mandelbrot();
	// else if (ft_strcmp(argv[1],"Julia") && argc == 2)  
		// plot_julia();
	// else
		// return(print_available_parameters());
}