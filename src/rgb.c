/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:24:19 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/26 15:59:48 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		rgb(int ***tab, t_fractal *bud, t_fractol *fract)
{
	char	*str;
	char	*tmp;
	int		nbr;

	if (!bud || !fract)
		ft_putstr("aie\n");
	str = (char*)malloc(sizeof(char) * 7);
	tmp = (char*)malloc(sizeof(char) * 3);
}
