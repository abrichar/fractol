/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:37:55 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/23 18:44:11 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    mandelbrot(t_fractol *fract)
{
    int x;
    int y;
    double x1;
    double x2;
    double y1;
    double y2;
    double zoomx;
    double zoomy;
    int i_max;
    double img_x;
    double img_y;
    double c_r;
    double c_i;
    double z_r;
    double z_i;
    int i;
    double tmp;

    x1 = -2.1;
    x2 = 0.6;
    y1 = -1.2;
    y2 = 1.2;
    i_max = 50;
    img_x = PIXEL_X;
    img_y = PIXEL_Y;
    zoomx = img_x / (x2 - x1);
    zoomy = img_y / (y2 - y1);
    x = 0;
    while (x < img_x)
    {
        y = 0;
        while (y < img_y)
        {
            c_r = x / zoomx + x1;
            c_i = y / zoomy + y1;
            z_r = 0;
            z_i = 0;
            i = 0;
            while ((z_r * z_r + z_i * z_i) < 4 && i < i_max)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                i++;
            }
            if (i == i_max)
                fill_pixel(&fract->img, x, y, 0x0000FF);//bleu
            else
                fill_pixel(&fract->img, x, y, 0x000000);//bleu
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->mlx, fract->win,
                            fract->img.ptr, 0, 0);
}
