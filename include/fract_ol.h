/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbourji <adbourji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:35:35 by adbourji          #+#    #+#             */
/*   Updated: 2024/06/13 00:09:49 by adbourji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MESSAGE \
	"Usage: ./fract_ol mandelbrot\n.\
/fract_ol julia <real> <imaginary>\n"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_map_args
{
	double	unscaled_num;
	double	start1;
	double	stop1;
	double	start2;
	double	stop2;
}			t_map_args;

// colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
// psychedelic colors
# define LIME 0x00FF00
# define LAVA 0xFF0000
# define SKY 0x00FFFF
# define LAVA_RED 0xFF4500
# define LAVA_YELLOW 0xFFD700
# define LAVA_GREEN 0x00FF00
# define LAVA_BLUE 0x0000FF

size_t		ft_strlen(char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(char *s);

void		ft_fractal_init(t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);

t_complex	sum_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex a);

int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_img *img, int color);

int			mouse_handler(int button, int x, int y, t_fractal *fractal);

double		map(double unscaled_num, double new_min, double new_max,
				double old_max);

void		calculate_z(t_complex *z, t_complex *ztmp, t_complex *c);
void		handle_pixel_julia(int x, int y, t_fractal *fractal);

#endif