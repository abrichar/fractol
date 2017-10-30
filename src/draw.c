/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:02:29 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/30 15:51:07 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fill_pixel(t_img *img, int x, int y, int color)
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

unsigned int	getcol(unsigned int const iteration, unsigned int const max,
	int change)
{
	const float		coef = (float)max / (float)iteration;
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;
	unsigned int	color;

	red = (unsigned char)((float)0xff * coef);
	blue = (unsigned char)((float)0x0000ff * coef);
	green = (unsigned char)((float)0x00ff * coef);
	if (change == 0)
		color = ((unsigned int)red) << 16 | 0x0a40;
	else if (change == 1)
		color = ((unsigned int)green) << 8 | 0x0a40;
	else
		color = ((unsigned int)blue) << 4 | 0x0a40;
	return (color);
}
