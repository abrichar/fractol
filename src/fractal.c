/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:17:22 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/28 20:07:24 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change(t_fractal *fractal, t_fractol *fract)
{
	if (strcmp(fract->name, "Julia"))
		julia2(fractal, fract);
	else if (strcmp(fract->name, "Mandelbrot"))
		mandelbrot2(fractal, fract);
	if (strcmp(fract->name, "Burning Ship"))
		burning2(fractal, fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.ptr, 0, 0);
}

void	zoom(t_fractal *fractal, t_fractol *fract, int x, int y)
{
	fractal->zoom *= 2;
	fractal->tmpx = fractal->x1 + x * (fractal->x2 - fractal->x1) /
		(fractal->img_x - 50);
	fractal->tmpy = fractal->y1 + y * (fractal->y2 - fractal->y1) /
		(PIXEL - 20);
	fractal->tmpx2 = fractal->x1;
	fractal->tmpy2 = fractal->y1;
	fractal->x1 = fractal->tmpx - (fractal->x2 - fractal->x1) / 4;
	fractal->x2 = fractal->tmpx + (fractal->x2 - fractal->tmpx2) / 4;
	fractal->y1 = fractal->tmpy - (fractal->y2 - fractal->y1) / 4;
	fractal->y2 = fractal->tmpy + (fractal->y2 - fractal->tmpy2) / 4;
	change(fractal, fract);
}

void	dezoom(t_fractal *fractal, t_fractol *fract, int x, int y)
{
	if (fractal->zoom > 250)
	{
		fractal->zoom /= 2;
		fractal->tmpx = fractal->x1 + x * (fractal->x2 - fractal->x1) /
			fractal->img_x;
		fractal->tmpy = fractal->y1 + y * (fractal->y2 - fractal->y1) /
			PIXEL;
		fractal->tmpx2 = fractal->x1;
		fractal->tmpy2 = fractal->y1;
		fractal->x1 = fractal->tmpx - (fractal->x2 - fractal->x1);
		fractal->x2 = fractal->tmpx + (fractal->x2 - fractal->tmpx2);
		fractal->y1 = fractal->tmpy - (fractal->y2 - fractal->y1);
		fractal->y2 = fractal->tmpy + (fractal->y2 - fractal->tmpy2);
		change(fractal, fract);
	}
}

int		mouse_hook(int keycode, int x, int y, t_fractol *fract)
{
	if (y > 0)
	{
		if ((keycode == 1 || keycode == 5) && x <= fract->fractal->img_x)
			zoom(fract->fractal, fract, x, y);
		if ((keycode == 2 || keycode == 4) && x <= fract->fractal->img_x)
			dezoom(fract->fractal, fract, x, y);
	}
	return (0);
}
