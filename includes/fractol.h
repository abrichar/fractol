/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:46:34 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/28 20:05:19 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h> ////////////////////////////
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# define PIXEL 1000

typedef struct s_img
{
	void		*ptr;
	int			bpp;
	int			s_line;
	int			endian;
	char		*data;
}				t_img;

typedef struct	s_fractal
{
	int			x;
	int			y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	int			i_max;
	double		img_y;
	double		img_x;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			i;
	double		tmp;
	double		tmpx;
	double		tmpy;
	double		tmpx2;
	double		tmpy2;
}				t_fractal;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	char		*name;
	int			mid_x;
	int			mid_y;
	t_img		img;
	int			bpp;
	int			s_line;
	int			endian;
	t_fractal	*fractal;
}				t_fractol;

void   			fill_pixel(t_img *img, int x, int y, int color);
void			mandelbrot(t_fractol *fract, t_fractal *mand);
void			mandelbrot2(t_fractal *mand, t_fractol *fract);
void			julia(t_fractol *fract, t_fractal *julia);
void			julia2(t_fractal *julia, t_fractol *fract);
void			burning(t_fractol *fract, t_fractal *burn);
void			burning2(t_fractal *burn, t_fractol *fract);
void			change(t_fractal *fractal, t_fractol *fract);
void			zoom(t_fractal *fractal, t_fractol *fract, int x, int y);
void			dezoom(t_fractal *fractal, t_fractol *fract, int x, int y);
int				julia_hook(int x, int y, t_fractol *fract);
int				mouse_hook(int keycode, int x, int y, t_fractol *fract);
#endif
