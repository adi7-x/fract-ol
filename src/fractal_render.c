/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:23:55 by adbourji          #+#    #+#             */
/*   Updated: 2024/06/13 02:52:09 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	pixel;

	pixel = (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + pixel) = color;
}

static void	calculate_mandelbrot(t_complex *z, t_complex *c, int *i,
		t_fractal *fractal)
{
	t_complex	ztmp;

	while (*i < fractal->iterations)
	{
		ztmp = *z;
		z->x = (ztmp.x * ztmp.x) - (ztmp.y * ztmp.y);
		z->y = 2 * ztmp.x * ztmp.y;
		z->x = z->x + c->x;
		z->y = z->y + c->y;
		if ((z->x * z->x) + (z->y * z->y) > fractal->escape_value)
		{
			return ;
		}
		(*i)++;
	}
}

static void	handle_pixel_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = map(x, -2, +2, WIDTH) * fractal->zoom + fractal->shift_x;
	z.y = map(y, -2, +2, HEIGHT) * fractal->zoom + fractal->shift_y;
	c.x = z.x;
	c.y = z.y;
	calculate_mandelbrot(&z, &c, &i, fractal);
	if (i < fractal->iterations)
	{
		color = map(i, BLACK, LAVA, fractal->iterations);
		my_pixel_put(x, y, &fractal->img, color);
	}
	else
	{
		my_pixel_put(x, y, &fractal->img, WHITE);
	}
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;

	x = 0;
	while (x < WIDTH * HEIGHT)
	{
		if (ft_strcmp(fractal->name, "mandelbrot") == 0)
			handle_pixel_mandelbrot(x % WIDTH, x / WIDTH, fractal);
		else if (ft_strcmp(fractal->name, "julia") == 0)
			handle_pixel_julia(x % WIDTH, x / WIDTH, fractal);
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
