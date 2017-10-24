/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:37:55 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/24 18:05:22 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot2(t_mandelbrot *mand, t_fractol *fract)
{
	mand->c_r = mand->x / mand->zoomx + mand->x1;
	mand->c_i = mand->y / mand->zoomy + mand->y1;
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
	if (mand->i == mand->i_max)
		fill_pixel(&fract->img, mand->x, mand->y, 0x0000FF);
	else
		fill_pixel(&fract->img, mand->x, mand->y, 0x000000);
	mand->y++;
}

void		mandelbrot(t_fractol *fract)
{
	t_mandelbrot mand;

	mand.x1 = -2.1;
	mand.x2 = 0.6;
	mand.y1 = -1.2;
	mand.y2 = 1.2;
	mand.i_max = 50;
	mand.img_x = PIXEL_X;
	mand.img_y = PIXEL_Y;
	mand.zoomx = mand.img_x / (mand.x2 - mand.x1);
	mand.zoomy = mand.img_y / (mand.y2 - mand.y1);
	mand.x = 0;
	while (mand.x < mand.img_x)
	{
		mand.y = 0;
		while (mand.y < mand.img_y)
		{
			mandelbrot2(&mand, fract);
		}
		mand.x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win,
			fract->img.ptr, 0, 0);
}
