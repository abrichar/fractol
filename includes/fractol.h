/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:46:34 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/13 18:05:16 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# define PIXEL_X 1000
# define PIXEL_Y 1000

typedef struct s_img
{
	void		*ptr;
	int			bpp;
	int			s_line;
	int			endian;
	int			*data;
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

void   			fill_pixel(int *data, int x, int y, int color);
void			mandelbrot(t_fractol *fract);
#endif
