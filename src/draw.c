/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:02:29 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/14 13:06:30 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(t_img *img, int x, int y, int color)
{
	int r;
	int g;
	int b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && PIXEL_X > x && PIXEL_Y > y)
	{
		img->data[(y * img->s_line) + ((img->bpp / 8) * x) + 2] = r;
		img->data[(y * img->s_line) + ((img->bpp / 8) * x) + 1] = g;
		img->data[(y * img->s_line) + ((img->bpp / 8) * x)] = b;
	}
}

void	mandelbrot(t_fractol *fract)
{
	int x;
	int y;
	float x1;
	float x2;
	float y1;
	float y2;
	int zoom;
	int i_max;
	float img_x;
	float img_y;
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	int i;
	int tmp;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 100;
	i_max = 50;
	img_x = (x2 - x1) * zoom;
	img_y = (y2 - y1) * zoom;
	x = 0;
	y = 0;
	while (x < img_x)
	{
		while (y < img_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == i_max)
				fill_pixel(&fract->img, x, y, 0xFF0000);
			else
				fill_pixel(&fract->img, x, y, 0x0000FF);
			y++;
		}
		x++;
	}
	fill_pixel(&fract->img, PIXEL_X / 2, PIXEL_Y / 2, 0x00FF00);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.ptr, 0, 0);
}
