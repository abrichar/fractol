/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:09:20 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/27 02:39:32 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia2(t_fractal *julia, t_fractol *fract)
{
	julia->x = 0;
	while (julia->x < julia->img_x)
	{
		julia->y = 0;
		while (julia->y < julia->img_y)
		{
			julia->c_r = 0.285;
			julia->c_i = 0.01;
			julia->z_r = julia->x / julia->zoomx + julia->x1;
			julia->z_i = julia->y / julia->zoomy + julia->y1;
			julia->i = 0;
			while (julia->z_r * julia->z_r + julia->z_i * julia->z_i < 4 &&
				   julia->i < julia->i_max)
			{
				julia->tmp = julia->z_r;
				julia->z_r = julia->z_r * julia->z_r - julia->z_i * julia->z_i
					+ julia->c_r;
				julia->z_i = 2 * julia->z_i * julia->tmp + julia->c_i;
				julia->i++;
			}
			if (julia->i == julia->i_max)
				fill_pixel(&fract->img, julia->x, julia->y, 0x0000FF);
			julia->y++;
		}
		julia->x++;
	}
	fract->fractal = *julia;
}

void	julia(t_fractol *fract)
{
	t_fractal julia;

	julia.x1 = -1;
	julia.x2 = 1;
	julia.y1 = -1.2;
	julia.y2 = 1.2;
	julia.i_max = 50;
	julia.img_x = PIXEL_X;
	julia.img_y = PIXEL_Y;
	julia.zoomx = julia.img_x / (julia.x2 - julia.x1);
	julia.zoomy = julia.img_y / (julia.y2 - julia.y1);
	julia2(&julia, fract);
}
