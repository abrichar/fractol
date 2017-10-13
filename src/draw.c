/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:02:29 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/13 18:43:14 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(int *data, int x, int y, int color)
{
	data[y * PIXEL_X + x] = color;
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
	int img_x;
	int img_y;
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
			{
				fract->img.data[y * PIXEL_X + x] = 0;
				fill_pixel(fract->img.data, x, y, 0xFFFFFF);
			}
			else
			{
				fract->img.data[y * PIXEL_X + x] = 9;
				fill_pixel(fract->img.data, x, y, 0x000000);
			}
			y++;
		}
		x++;
	}
	fill_pixel(fract->img.data, PIXEL_X / 2, PIXEL_Y / 2, 0xFFFFFF);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.ptr, 0, 0);
}
