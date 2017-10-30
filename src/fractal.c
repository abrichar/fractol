/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:17:22 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/30 16:14:29 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change(t_fractal *fractal, t_fractol *fract)
{
	mlx_clear_window(fract->mlx, fract->win);
	mlx_destroy_image(fract->mlx, fract->img.ptr);
	fract->img.ptr = mlx_new_image(fract->mlx, fractal->img_x, PIXEL_Y);
	if (ft_strcmp(fract->name, "Julia") == 0)
		julia2(fractal, fract);
	else if (ft_strcmp(fract->name, "Mandelbrot") == 0)
		mandelbrot2(fractal, fract);
	else if (ft_strcmp(fract->name, "Burning Ship") == 0)
		burning2(fractal, fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.ptr,
							fract->move_x, fract->move_y);
}

void	zoom(t_fractal *fractal, t_fractol *fract, int x, int y)
{
	fractal->zoom *= 2;
	fractal->tmpx = fractal->x1 + x * (fractal->x2 - fractal->x1) /
		(fractal->img_x - 50);
	fractal->tmpy = fractal->y1 + y * (fractal->y2 - fractal->y1) /
		(PIXEL_Y - 20);
	fractal->tmpx2 = fractal->x1;
	fractal->tmpy2 = fractal->y1;
	fractal->x1 = fractal->tmpx - (fractal->x2 - fractal->x1) / 4;
	fractal->x2 = fractal->tmpx + (fractal->x2 - fractal->tmpx2) / 4;
	fractal->y1 = fractal->tmpy - (fractal->y2 - fractal->y1) / 4;
	fractal->y2 = fractal->tmpy + (fractal->y2 - fractal->tmpy2) / 4;
	fractal->i_max += 5;
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
			PIXEL_Y;
		fractal->tmpx2 = fractal->x1;
		fractal->tmpy2 = fractal->y1;
		fractal->x1 = fractal->tmpx - (fractal->x2 - fractal->x1);
		fractal->x2 = fractal->tmpx + (fractal->x2 - fractal->tmpx2);
		fractal->y1 = fractal->tmpy - (fractal->y2 - fractal->y1);
		fractal->y2 = fractal->tmpy + (fractal->y2 - fractal->tmpy2);
		fractal->i_max -= 5;
		change(fractal, fract);
	}
}

int		mouse_hook(int keycode, int x, int y, t_fractol *fract)
{
	if (y > 0 && x <= fract->fractal->img_x)
	{
		if ((keycode == 1 || keycode == 5))
			zoom(fract->fractal, fract, x, y);
		if ((keycode == 2 || keycode == 4))
			dezoom(fract->fractal, fract, x, y);
	}
	return (0);
}
