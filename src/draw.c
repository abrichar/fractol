/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:02:29 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/28 19:16:27 by abrichar         ###   ########.fr       */
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
	if (y >= 0 && x >= 0 && PIXEL > x && PIXEL > y)
	{
		img->data[(y * img->s_line) + ((img->bpp / 8) * x) + 2] = r;
		img->data[(y * img->s_line) + ((img->bpp / 8) * x) + 1] = g;
		img->data[(y * img->s_line) + ((img->bpp / 8) * x)] = b;
	}
}
