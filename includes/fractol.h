/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:46:34 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/26 17:40:23 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h> ////////////////////////////
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# define PIXEL_X 500
# define PIXEL_Y 500

typedef struct s_img
{
	void		*ptr;
	int			bpp;
	int			s_line;
	int			endian;
	char		*data;
}				t_img;

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
}				t_fractol;

typedef struct	s_fractal
{
	int			x;
	int			y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoomx;
	double		zoomy;
	int			i_max;
	double		img_y;
	double		img_x;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			i;
	double		tmp;
}				t_fractal;

void   			fill_pixel(t_img *img, int x, int y, int color);
void			mandelbrot(t_fractol *fract);
void			mandelbrot2(t_fractal *mand, t_fractol *fract);
void			julia(t_fractol *fract);
void			julia2(t_fractal *julia, t_fractol *fract);
void			burning(t_fractol *fract);
void			burning2(t_fractal *burn, t_fractol *fract);
void			change(t_fractal *fractal, t_fractol *fract);
void			zoom(t_fractal *fractal, t_fractol *fract);
//void			rgb(int ***tab, t_fractal *bud, t_fractol *fract);
#endif
