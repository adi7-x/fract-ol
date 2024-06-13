/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:11:00 by adbourji          #+#    #+#             */
/*   Updated: 2024/06/13 02:51:59 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	calculate_z(t_complex *z, t_complex *ztmp, t_complex *c)
{
	ztmp->x = z->x;
	ztmp->y = z->y;
	z->x = (ztmp->x * ztmp->x) - (ztmp->y * ztmp->y);
	z->y = 2 * ztmp->x * ztmp->y;
	z->x = z->x + c->x;
	z->y = z->y + c->y;
}

void	handle_pixel_julia(int x, int y, t_fractal *fractal)
{
	int			i;
	int			color;
	t_complex	ztmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = map(x, -2, +2, WIDTH) * fractal->zoom + fractal->shift_x;
	z.y = map(y, -2, +2, HEIGHT) * fractal->zoom + fractal->shift_y;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	while (i < fractal->iterations)
	{
		calculate_z(&z, &ztmp, &c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, LAVA, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}
