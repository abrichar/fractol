/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:50:52 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/25 22:06:13 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:11:33 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/25 21:49:50 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	buddhabrot2(t_fractal *bud, t_coord *tmp_pixels)
{
	bud->c_r = bud->x / bud->zoomx + bud->x1;
	bud->c_i = bud->y / bud->zoomy + bud->y1;
	bud->z_r = 0;
	bud->z_i = 0;
	bud->i = 0;
	while (bud->z_r * bud->z_r + bud->z_i * bud->z_i < 4 &&
		   bud->i < bud->i_max)
	{
		bud->tmp = bud->z_r;
		bud->z_r = bud->z_r * bud->z_r - bud->z_i * bud->z_i
			+ bud->c_r;
		bud->z_i = 2 * bud->z_i * bud->tmp + bud->c_i;
		tmp_pixels[bud->i].x = (bud->z_r - bud->x1) * bud->zoomx;
		tmp_pixels[bud->i].y = (bud->z_i - bud->y1) * bud->zoomy;
		bud->i++;
	}
}

static void	buddhabrot3(t_fractal *bud, int i_color, int **tab,
						t_coord *tmp_pixels)
{
	int cmp;

	
	printf("start\n");
	if (bud->i < i_color)
	{
		cmp = 0;
		printf("check 1\n");
		while (cmp < bud->i)
		{
			printf("cmp = %d\n", cmp);
			printf("test 1: %d\n", tmp_pixels[cmp].x);
			printf("test 2: %d\n", tmp_pixels[cmp].y);
			printf("test 3: %d\n", tab[tmp_pixels[cmp].x][tmp_pixels[cmp].y]);
			printf("check 2\n");
			if (tab[tmp_pixels[cmp].x][tmp_pixels[cmp].y])
			{
				printf("check 3\n");
					sleep(1000);
				(tab[tmp_pixels[cmp].x][tmp_pixels[cmp].y])++;
			}
			cmp++;
		}
	}
	printf("end\n");
}

static void	init_bud(t_fractal *bud)
{
	bud->x1 = -2.1;
	bud->x2 = 0.6;
	bud->y1 = -1.2;
	bud->y2 = 1.2;
	bud->i_max = 10000;
	bud->img_x = PIXEL_X;
	bud->img_y = PIXEL_Y;
	bud->zoomx = bud->img_x / (bud->x2 - bud->x1);
	bud->zoomy = bud->img_y / (bud->y2 - bud->y1);
	bud->x = 0;
}

int		buddhabrot(t_fractol *fract)
{
	t_fractal	bud;
	int i_color[3];
	int ***tab;
	t_coord *tmp_pixels;

	init_bud(&bud);
	i_color[0] = 100;
	i_color[1] = 1000;
	i_color[2] = 10000;
	tab = (int***)malloc(sizeof(int**) * (PIXEL_X * PIXEL_Y * 3 + 1));
	tab[0] = ft_tabint(PIXEL_X, PIXEL_Y);
	tab[1] = ft_tabint(PIXEL_X, PIXEL_Y);
	tab[2] = ft_tabint(PIXEL_X, PIXEL_Y);
	tmp_pixels = (t_coord*)malloc(sizeof(t_coord) * PIXEL_X * PIXEL_Y); //malloc
	while (bud.x < bud.img_x)
	{
		bud.y = 0;
		while (bud.y < bud.img_y)
		{
			buddhabrot2(&bud, tmp_pixels);
			printf("a\n");
			buddhabrot3(&bud, i_color[0], tab[0], tmp_pixels);
			printf("b\n");
			buddhabrot3(&bud, i_color[1], tab[1], tmp_pixels);
			printf("c\n");
			buddhabrot3(&bud, i_color[2], tab[2], tmp_pixels);
			printf("d\n");
			bud.y++;
		}
		bud.x++;
	}
	rgb(tab, &bud, fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.ptr,
							0, 0);
	return (1);
}

