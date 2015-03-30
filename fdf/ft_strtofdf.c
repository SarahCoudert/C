/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtofdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <scoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:36:22 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/30 11:10:48 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
 ** Transforme un tableau de char contenant des chiffres separes par des espaces
 ** en un tableau d'int.
 */
static void		free_all(char **split, size_t *color)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(color);
}

static void		fill_struct(int y, int x, char *prev_z, t_fdf *res, int color)
{
	t_fdf	str;

	str = *res;
	str.x = x;
	str.y = y;
	str.z = ft_atoi(prev_z);
	str.color = color;
	str.aff_c.color = -1;
	str.aff_c.red = -1;
	str.aff_c.blue= -1;
	str.aff_c.green = -1;
	str.aff_x = 0;
	str.aff_y = 0;
	*res = str;
}

int				wrong_value(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '-' && s[i] != ',' &&
			(s[i] != '0' && (s[i + 1] != 'X' || s[i + 1] != 'x')) &&
			((s[i] != 'x' || s[i] != 'X') && s[i - 1] != '0')
			&& ft_hexatodeci(s) == -42)
		{
			ft_putstr_fd("Error : Wrong value \"", 2);
			ft_putchar_fd(s[i], 2);
			ft_putendl_fd("\" in map. Program abort.", 2);
			return (-1);
		}
		else
			i++;
	}
	return (0);
}

t_fdf			*ft_strtofdf(const char *s, int line, int i)
{
	t_fdf		*result;
	char		**split;
	int			words;
	size_t		*color;

	color = NULL;
	words = countword(s, ' ');
	result = NULL;
	if ((result = (t_fdf*)ft_memalloc(sizeof(t_fdf) * (words + 1))) == NULL)
		return (NULL);
	if ((color = (size_t*)ft_memalloc(sizeof(size_t) * words))  == NULL)
		return (NULL);
	split = ft_strsplit(s, ' ');
	while (i < words && split[i])
	{
		if (wrong_value(split[i]) < 0)
		{
			exit (-1);
		}
		color[i] = ft_hexatodeci(split[i]);
		i++;
	}
	i = 0;
	while (i < words && split[i])
	{
		fill_struct(line, i, split[i], result + i, (int)color[i]);
		i++;
	}
	result[words].x = (-42);
	result[words].y = (-42);
	free_all(split, color);
	return (result);
}
