/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:46:51 by scoudert          #+#    #+#             */
/*   Updated: 2015/03/09 18:05:55 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "fractol.h"

int					rgbtoint(int r, int g, int b)
{
	unsigned int	color;

	color = r << 16;
	color += g << 8;
	color += b;
	return (color);
}

void		put_pixel_image(t_env *env, double x, double y, int color)
{
	t_img	*img;
	int		octets;
	int		k;

	img = env->img;
	octets = img->bpp / 8;
	env->img;
}

int			ft_color(double pos)
{
	int		hex;
	double	p;
	double	fpart;
	int		a;

	if (pos > 1.0)
		pos = (pos - (int)pos) == 0.0 ? 1.0 : (pos - (int)pos);
	p = 6 * pos;
	fpart = p - (int)p;
	a = (int)(fpart * 255);
	if ((int)p == 0)
		hex = rgbtoint(0, a, 0);
	else if ((int)p == 1)
		hex = rgbtoint(255 - a, 255, 0);
	else if ((int)p == 2)
		hex = rgbtoint(0, 255, a);
	else if ((int)p == 3)
		hex = rgbtoint(a, 255 - a, 255);
	else if ((int)p == 4)
		hex = rgbtoint(a, 0, 255);
	else if ((int)p == 5)
		hex = rgbtoint(0, 0, 255 - a);
	else
		hex = rgbtoint(0, 0, 0);
	return (hex);
}

void	draw(void *mlx, void *win, t_rgb *rgb, t_env *env)
{
	double			x;
	double			y;
	double			x_temp;
	unsigned int	max_iteration;
	unsigned int	iteration;
	unsigned int	xz;
	unsigned int	yz;
	int				color;

	x = 0.0;
	y = 0.0;
	x_temp = 0.0;
	iteration = 0;
	max_iteration = 1000;
	while (x * x + y * y < 2 * 2  && iteration < max_iteration)
	{
		x_temp = x * x - y * y + xz;
		y = 2 * x * y + yz;
		x = x_temp;
		iteration = iteration + 1;
		color = ft_color(x);
		put_pixel_image(env, x, y, color);
	}
}

int		expose_hook(t_env *env)
{
	draw(env->mlx, env->win, env->rgb, env);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else
		return (0);
}

int		main(int ac, char **av)
{
	t_env	env;
	t_rgb	*rgb;

	rgb = malloc(sizeof(rgb));
	rgb->r = 255;
	rgb->g = 0;
	rgb->b = 0;
	rgb->color = rgbtoint(rgb->r, rgb->g, rgb->b);
	env.rgb = rgb;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fractol");
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
