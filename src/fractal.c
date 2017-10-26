/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:17:22 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/26 17:41:04 by abrichar         ###   ########.fr       */
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
}

void	zoom(t_fractal *fractal, t_fractol *fract)
{
	fractal->zoomx *= 2;
	fractal->zoomy *= 2;
	fractal->x1 += 0.1;
	fractal->y2 -= 0.1;
	fractal->i_max += 10;
	change(fractal, fract);
}
