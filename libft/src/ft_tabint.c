/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:10:11 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/31 17:51:09 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_tabint(int x, int y)
{
	int **tab;
	int	index;
	int indey;

	if (!(tab = (int**)malloc(sizeof(int*) * (x * y + 1))))
		return (NULL);
	index = 0;
	while (index < x)
	{
		if (!(tab[index] = (int*)malloc(sizeof(int) * (x + 1))))
			return (NULL);
		indey = 0;
		while (indey < y)
		{
			tab[index][indey] = 0;
			indey++;
		}
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
