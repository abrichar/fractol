/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:02:29 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/13 16:07:56 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(int *data, int x, int y, int color)
{
	ft_putnbr((y * PIXEL_X + x));
	data[y * PIXEL_X + x] = color;
}
