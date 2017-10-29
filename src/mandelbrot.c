/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:37:55 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/29 22:32:20 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot2(t_fractal *mand, t_fractol *fract)
{
	mand->x = 0;
	while (mand->x < mand->img_x)
	{
		mand->y = 0;
		while (mand->y < mand->img_y)
		{
			mand->c_r = mand->x / mand->zoom + mand->x1;
			mand->c_i = mand->y / mand->zoom + mand->y1;
			mand->z_r = 0;
			mand->z_i = 0;
			mand->i = 0;
			while ((mand->z_r * mand->z_r + mand->z_i * mand->z_i) < 4
				   && mand->i < mand->i_max)
			{
				mand->tmp = mand->z_r;
				mand->z_r = mand->z_r * mand->z_r - mand->z_i *
					mand->z_i + mand->c_r;
				mand->z_i = 2 * mand->z_i * mand->tmp + mand->c_i;
				mand->i++;
			}
			fill_pixel(&fract->img, mand->x, mand->y,
					   getcol((unsigned int)mand->i_max,
							  (unsigned int)mand->i));
			mand->y++;
		}
		mand->x++;
	}
}

void		mandelbrot(t_fractol *fract, t_fractal *mand)
{
	mand->x1 = -2.1;
	mand->x2 = 0.6;
	mand->y1 = -1.2;
	mand->y2 = 1.2;
	mand->i_max = 100;
	mand->img_x = PIXEL_X;
	mand->img_y = PIXEL_Y;
	mand->zoom = mand->img_x / (mand->x2 - mand->x1);
	mandelbrot2(mand, fract);
}
