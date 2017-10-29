/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:09:20 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/29 17:20:14 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_hook(int x, int y, t_fractol *fract)
{
	if (ft_strcmp(fract->name, "Julia") == 0 && x <= fract->fractal->img_x &&
		y <= PIXEL && x > 0 && y > 0)
	{
		mlx_clear_window(fract->mlx, fract->win);
		mlx_destroy_image(fract->mlx, fract->img.ptr);
		fract->img.ptr = mlx_new_image(fract->mlx, fract->fractal->img_x,
									   PIXEL);
		fract->fractal->c_r = (x + 400 - fract->fractal->img_x) / 300;
		fract->fractal->c_i = (y + 320 - PIXEL) / 300;
		change(fract->fractal, fract);
	}
	return (0);
}

void	julia2(t_fractal *julia, t_fractol *fract)
{
	julia->x = 0;
	while (julia->x < julia->img_x)
	{
		julia->y = 0;
		while (julia->y < julia->img_y)
		{
			julia->z_r = julia->x / julia->zoom + julia->x1;
			julia->z_i = julia->y / julia->zoom + julia->y1;
			julia->i = 0;
			while (julia->z_r * julia->z_r + julia->z_i * julia->z_i < 4 &&
				   julia->i < julia->i_max)
			{
				julia->tmp = julia->z_r;
				julia->z_r = julia->z_r * julia->z_r - julia->z_i * julia->z_i
					+ julia->c_r;
				julia->z_i = 2 * julia->z_i * julia->tmp + julia->c_i;
				julia->i++;
			}
			if (julia->i == julia->i_max)
				fill_pixel(&fract->img, julia->x, julia->y, choose_color(julia->i));
			julia->y++;
		}
		julia->x++;
	}
}

void	julia(t_fractol *fract, t_fractal *julia)
{
	julia->c_r = 0.285;
	julia->c_i = 0.01;
	julia->x1 = -1;
	julia->x2 = 1;
	julia->y1 = -1.2;
	julia->y2 = 1.2;
	julia->i_max = 100;
	julia->img_x = PIXEL;
	julia->img_y = PIXEL;
	julia->zoom = julia->img_x / (julia->x2 - julia->x1);
	julia2(julia, fract);
}
