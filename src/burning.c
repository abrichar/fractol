/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:44:52 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/27 02:40:13 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning2(t_fractal *burn, t_fractol *fract)
{
    burn->x = 0;
    while (burn->x < burn->img_x)
    {
        burn->y = 0;
        while (burn->y < burn->img_y)
        {
			burn->c_r = burn->x / burn->zoomx + burn->x1;
			burn->c_i = burn->y / burn->zoomy + burn->y1;
			burn->z_r = burn->c_r;
			burn->z_i = burn->c_i;
			burn->i = 0;
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
			if (burn->i == burn->i_max)
				fill_pixel(&fract->img, burn->x, burn->y, 0x0000FF);
			else
				fill_pixel(&fract->img, burn->x, burn->y, 0x000000);
			burn->y++;
        }
        burn->x++;
    }
	fract->fractal = *burn;
}

void        burning(t_fractol *fract)
{
	t_fractal burn;

    burn.x1 = -1.8;
    burn.x2 = -1.6;
    burn.y1 = -0.13;
    burn.y2 = 0.02;
    burn.i_max = 25;
    burn.img_x = PIXEL_X;
    burn.img_y = PIXEL_Y;
    burn.zoomx = burn.img_x / (burn.x2 - burn.x1);
    burn.zoomy = burn.img_y / (burn.y2 - burn.y1);
	burning2(&burn, fract);
}
