/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:39:43 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/14 11:57:03 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		key_react(int keycode, t_fractol *fract)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

static int		select_fractal(char *name, t_fractol *fract)
{
	if (strcmp(name, "Julia") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 6);
		fract->name = "Julia";
	}
	else if (strcmp(name, "Mandelbrot") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 11);
		fract->name = "Mandelbrot";
	}
	else if (strcmp(name, "test01") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 7);
		fract->name = "test01";
	}
	else
		return (0);
	return (1);
}

static void		init_fract(t_fractol *fract)
{
	fract->mid_x = PIXEL_X / 2;
	fract->mid_y = PIXEL_Y / 2;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, PIXEL_X, PIXEL_Y, fract->name);
	fract->img.bpp = 0;
	fract->img.s_line = 0;
	fract->img.endian = 0;
	fract->img.ptr = mlx_new_image(fract->mlx, PIXEL_X, PIXEL_Y);
	fract->img.data = (char *)mlx_get_data_addr(fract->img.ptr, &(fract->img.bpp),
						&(fract->img.s_line), &(fract->img.endian));
}

int				main(int argc, char **argv)
{
	t_fractol fract;

	if (argc != 2 || (select_fractal(argv[1], &fract)) == 0)
	{
		ft_putstr("usage: ./fractol Julia | ./fractol Mandelbrot ");
		ft_putstr("| ./fractol test01\n");
		return (0);
	}
	init_fract(&fract);
	mandelbrot(&fract);
	mlx_key_hook(fract.win, key_react, &fract);
	mlx_loop(fract.mlx);
	return (0);
}
