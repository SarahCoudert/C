/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 11:13:30 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/30 11:04:07 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		test_get_map(t_fdf **s)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		printf("Nous sommes ligne %d\n", i);
		while (s[i][j].x >= 0)
		{
			printf("Nous sommes a l'index %d :\n", j);
			printf("Couleur : %d\n", s[i][j].color);
			j++;
		}
		j = 0;
		ft_putendl("");
		i++;
	}
}
