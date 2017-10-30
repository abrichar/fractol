/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyreact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:06:30 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/30 17:14:21 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define KEY_I 34
#define KEY_O 31
#define KEY_S 1
#define KEY_A 0
#define KEY_R 15
#define KEY_G 5
#define KEY_B 11
#define LEFT  123
#define RIGHT 124
#define BOT   125
#define TOP   126
#define ESC	  53

static void	key_react2(int keycode, t_fractol *fract)
{
	if (keycode == LEFT)
		fract->move_x--;
	else if (keycode == RIGHT)
		fract->move_x++;
	else if (keycode == BOT)
		fract->move_y++;
	else if (keycode == TOP)
		fract->move_y--;
}

int			key_react(int keycode, t_fractol *fract)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_O)
		changeiter(fract, fract->fractal->i_max >> 1);
	else if (keycode == KEY_I)
		changeiter(fract, fract->fractal->i_max << 1);
	else if (keycode == KEY_S)
		fract->fractal->move = 0;
	else if (keycode == KEY_A)
		fract->fractal->move = 1;
	else if (keycode == KEY_R)
		fract->fractal->change_color = 0;
	else if (keycode == KEY_G)
		fract->fractal->change_color = 1;
	else if (keycode == KEY_B)
		fract->fractal->change_color = 2;
	else
		key_react2(keycode, fract);
	change(fract->fractal, fract);
	return (1);
}
