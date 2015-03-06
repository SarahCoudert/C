/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 11:48:54 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/06 17:17:41 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# define SCREEN_WIDTH		420
# define SCREEN_HEIGHT		420

typedef struct			s_rgb
{
	int			r;
	int			g;
	int			b;
	int			color;
}						t_rgb;

typedef struct			s_env
{
	t_rgb		*rgb;
	void		*mlx;
	void		*win;
}						t_env;

typedef struct			s_img
{
	int					width;
	int					height;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

#endif
