/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:39:43 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/30 17:14:37 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			changeiter(t_fractol *fract, int newval)
{
	fract->fractal->i_max = newval;
	if (!fract->fractal->i_max)
		fract->fractal->i_max = 1;
	change(fract->fractal, fract);
}

static int		select_fractal(char *name, t_fractol *fract)
{
	if (strcmp(name, "Julia") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 6);
		fract->name = "Julia";
		julia(fract, fract->fractal);
		fract->fractal->move = 1;
	}
	else if (strcmp(name, "Mandelbrot") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 11);
		fract->name = "Mandelbrot";
		mandelbrot(fract, fract->fractal);
	}
	else if (strcmp(name, "Burning Ship") == 0)
	{
		fract->name = (char *)malloc(sizeof(char) * 7);
		fract->name = "Burning Ship";
		burning(fract, fract->fractal);
	}
	else
		return (0);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.ptr,
							fract->move_x, fract->move_y);
	return (1);
}

static int		init_fract(t_fractol *fract, char *name)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, PIXEL_X, PIXEL_Y, name);
	fract->img.bpp = 0;
	fract->img.s_line = 0;
	fract->img.endian = 0;
	fract->img.ptr = mlx_new_image(fract->mlx, PIXEL_X, PIXEL_Y);
	fract->img.data = (char *)mlx_get_data_addr(fract->img.ptr,
		&(fract->img.bpp), &(fract->img.s_line), &(fract->img.endian));
	fract->fractal->move = 0;
	fract->fractal->change_color = 0;
	fract->move_x = 0;
	fract->move_y = 0;
	if (select_fractal(name, fract) == 0)
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_fractol fract;
	t_fractal fractal;

	fract.fractal = &fractal;
	if (argc != 2 || (init_fract(&fract, argv[1])) == 0)
	{
		ft_putstr("usage: ./fractol Julia | ./fractol Mandelbrot ");
		ft_putstr("| ./fractol \"Burning Ship\"\n");
		exit(EXIT_SUCCESS);
	}
	mlx_mouse_hook(fract.win, mouse_hook, &fract);
	mlx_hook(fract.win, 6, (1L << 6), julia_hook, &fract);
	mlx_key_hook(fract.win, key_react, &fract);
	mlx_loop(fract.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
