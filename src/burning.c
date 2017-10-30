/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:44:52 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/30 16:11:58 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		burning3(t_fractal *burn)
{
	while ((burn->z_r * burn->z_r + burn->z_i * burn->z_i) < 4
			&& burn->i < burn->i_max)
	{
		burn->tmp = burn->z_i;
		burn->z_i = fabs((double)burn->z_r * burn->z_i + burn->z_r *
				burn->z_i + burn->c_i);
		burn->z_r = fabs((double)burn->z_r * burn->z_r - burn->tmp *
				burn->tmp + burn->c_r);
		burn->i++;
	}
}

void			burning2(t_fractal *burn, t_fractol *fract)
{
	burn->x = 0;
	while (burn->x < burn->img_x)
	{
		burn->y = 0;
		while (burn->y < burn->img_y)
		{
			burn->c_r = burn->x / burn->zoom + burn->x1;
			burn->c_i = burn->y / burn->zoom + burn->y1;
			burn->z_r = burn->c_r;
			burn->z_i = burn->c_i;
			burn->i = 0;
			burning3(burn);
			if (burn->i == burn->i_max)
				fill_pixel(&fract->img, burn->x, burn->y, 0x0000FF);
			else
				fill_pixel(&fract->img, burn->x, burn->y,
						getcol((unsigned int)burn->i_max,
							(unsigned int)burn->i,
							burn->change_color));
			burn->y++;
		}
		burn->x++;
	}
}

void			burning(t_fractol *fract, t_fractal *burn)
{
	burn->x1 = -1.8;
	burn->x2 = -1.6;
	burn->y1 = -0.13;
	burn->y2 = 0.02;
	burn->i_max = 100;
	burn->img_x = PIXEL_X;
	burn->img_y = PIXEL_Y;
	burn->zoom = burn->img_x / (burn->x2 - burn->x1);
	burning2(burn, fract);
}
