/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:46:34 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/12 17:11:19 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# define PIXEL_X 800
# define PIXEL_Y 800

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	char		*name;
}				t_fractol;
#endif
