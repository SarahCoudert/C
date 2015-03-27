#include "fdf.h"

void	trace_0(t_trace t, t_env *env)
{
	while (t.y1 != t.y2 && t.dx == 0)
	{
		img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
		if (t.dy > 0)
			t.y1 = t.y1 + 1;
		if (t.dy < 0)
			t.y1 = t.y1 - 1;
	}
	while (t.x1 != t.x2 && t.dy == 0)
	{
		img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
		if (t.dx > 0)
			t.x1 = t.x1 + 1;
		if (t.dx < 0)
			t.x1 = t.x1 - 1;
	}
}

void	trace_1(t_trace t, int e, t_env *env)
{
	if (t.dx >= t.dy && (e = t.dx / 2))//premier octant
		while (t.x1 != t.x2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.x1 = t.x1 + 1;
			if ((e = e - t.dy) < 0)
			{
				t.y1 = t.y1 + 1;
				e = e + t.dx;
			}
		}
	else if (t.dx < t.dy && (e = t.dy / 2))//(t.dx < t.dy) ==> second octant
		while (t.y1 != t.y2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.y1 = t.y1 + 1;
			if ((e = e - t.dx) < 0)
			{
				t.x1 = t.x1 + 1;
				e = e + t.dy;
			}
		}
}

void	trace_2(t_trace t, int e, t_env *env)
{
	if ((t.dx * -1) >= t.dy && (e = t.dx / 2))//4* octant
		while (t.x1 != t.x2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.x1 = t.x1 - 1;
			if ((e = e + t.dy) >= 0)
			{
				t.y1 = t.y1 + 1;
				e = e + t.dx;
			}
		}
	else if (-t.dx < t.dy && (e = t.dy / 2))//3* octant
		while (t.y1 != t.y2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.y1 = t.y1 + 1;
			if ((e = e + t.dx) <= 0)
			{
				t.x1 = t.x1 - 1;
				e = e + t.dy;
			}
		}
}

void	trace_3(t_trace t, int e, t_env *env)
{
	if (t.dx <= t.dy && (e = t.dx / 2))//5* octant
		while (t.x1 != t.x2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.x1 = t.x1 - 1;
			if ((e = e - t.dy) >= 0)
			{
				t.y1 = t.y1 - 1;
				e = e + t.dx;
			}
		}
	else if (t.dx > t.dy && (e = t.dy / 2))//6* octant
		while (t.y1 != t.y2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.y1 = t.y1 - 1;
			if ((e = e - t.dx) >= 0)
			{
				t.x1 = t.x1 - 1;
				e = e + t.dy;
			}
		}
}

void	trace_4(t_trace t, int e, t_env *env)
{
	if (t.dx >= -t.dy && (e = t.dx / 2))//8* octant
		while (t.x1 != t.x2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.x1 = t.x1 + 1;
			if ((e = e + t.dy) < 0)
			{
				t.y1 = t.y1 - 1;
				e = e + t.dx;
			}
		}
	else//7* octant
	{
		e = t.dx / 2;
		while (t.y1 != t.y2)
		{
			img_pixel_put(env, t.x1, t.y1, ft_col(t, env));
			t.y1 = t.y1 - 1;
			if ((e = e + t.dx) > 0)
			{
				t.x1 = t.x1 + 1;
				e = e + t.dy;
			}
		}
	}
}
