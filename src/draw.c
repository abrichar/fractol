/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:02:29 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/29 02:51:11 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_color(int i)
{
	if (i < 10)
		return (0x000000);
	else if (i < 20)
		return (0x00FF00);
	else if (i < 30)
		return (0xFF0000);
	else if (i < 40)
		return (0xFFFFFF);
	else if (i < 50)
		return (0x0000FF);
	else if (i < 60)
		return (0xFF00F0);
	else if (i < 70)
		return (0xF0F0F0);
	else if (i < 80)
		return (0xFFF000);
	else if (i < 90)
		return (0x000FFF);
	else
		return (0xFFFFFF);

}

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
