/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:24:19 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/25 18:57:49 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		rgb(int ***tab, t_fractal *bud, t_fractol *fract)
{
	char	*str;
	char	*tmp;
	t_coord	coord;
	int		nbr;

	if (!bud || !fract)
		ft_putstr("aie\n");
	str = (char*)malloc(sizeof(char) * 7);
	tmp = (char*)malloc(sizeof(char) * 3);
	coord.x = 0;
	coord.y = 0;
	nbr = tab[0][coord.x][coord.y];
	tmp = ft_itoabaseu((unsigned long)nbr, 16, 0);
	printf("rgb : tmp : %s\n", tmp);
}
