/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:02:29 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/29 16:36:35 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_color(int i)
{
	if (i < 10)
		return (0x000000);
	else if (i < 20)
		return (0x330000);
	else if (i < 30)
		return (0x660000);
	else if (i < 40)
		return (0x990000);
	else if (i < 50)
		return (0xcc0000);
	else if (i < 60)
		return (0xff0000);
	else if (i < 70)
		return (0xff4d4d);
	else if (i < 80)
		return (0xff9999);
	else if (i < 90)
		return (0xffcccc);
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
