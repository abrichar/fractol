/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:39:43 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/25 16:46:16 by abrichar         ###   ########.fr       */
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
		julia(fract);
	}
	else if (strcmp(name, "Mandelbrot") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 11);
		fract->name = "Mandelbrot";
		mandelbrot(fract);
	}
	else if (strcmp(name, "Buddhabrot") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 7);
		fract->name = "Buddhabrot";
		if (buddhabrot(fract) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

static int		init_fract(t_fractol *fract, char *name)
{
	fract->mid_x = PIXEL_X / 2;
	fract->mid_y = PIXEL_Y / 2;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, PIXEL_X, PIXEL_Y, name);
	fract->img.bpp = 0;
	fract->img.s_line = 0;
	fract->img.endian = 0;
	fract->img.ptr = mlx_new_image(fract->mlx, PIXEL_X, PIXEL_Y);
	fract->img.data = (char *)mlx_get_data_addr(fract->img.ptr,
		&(fract->img.bpp), &(fract->img.s_line), &(fract->img.endian));
	if (select_fractal(name, fract) == 0)
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_fractol fract;

	if (argc != 2 || (init_fract(&fract, argv[1])) == 0)
	{
		ft_putstr("usage: ./fractol Julia | ./fractol Mandelbrot ");
		ft_putstr("| ./fractol Buddhabrot\n");
		return (0);
	}
	mlx_key_hook(fract.win, key_react, &fract);
	mlx_loop(fract.mlx);
	return (0);
}
