/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:22 by adbourji          #+#    #+#             */
/*   Updated: 2024/06/13 02:51:44 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot")) || (argc == 4
			&& !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(fractal.name, "julia"))
		{
			fractal.julia_x = ft_atod(argv[2]);
			fractal.julia_y = ft_atod(argv[3]);
		}
		ft_fractal_init(&fractal);
		ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(MESSAGE, 2);
		return (1);
	}
	return (0);
}
