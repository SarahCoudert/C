#include "fdf.h"

void	fdf_calcul_proj(t_fdf **s, t_env *env)
{
	int			i;
	int			j;
	t_v_map	*map;

	map = &(env->v_map);
	if (map->ecart == -42 && ((i = -1) + 2))
	{
		map->ecart = 1;
		while (s[++i] && ((j = -1) + 2))
			while (s[i][++j].x >= 0)
				s[i][j] = ft_proj_cal(s[i][j], env, i, j);
		map->ecart = map->win_x / (map->max_x + 1 - map->low_x);
		if (map->ecart > (map->win_y / (map->max_y + 1 - map->low_y)))
			map->ecart = map->win_y / (map->max_y + 1 - map->low_y);
	}
	if (map->ecart <= 0)
		map->ecart = 1;
	i = -1;
	while (s[++i] && ((j = -1) + 2))
		while (s[i][++j].x >= 0)
			s[i][j] = ft_proj_cal(s[i][j], env, i, j);
	i = -1;
	while (s[++i] && ((j = -1) + 2))
		while (s[i][++j].x >= 0)
		{
			s[i][j].aff_x = s[i][j].aff_x - map->low_x;
			s[i][j].aff_y = s[i][j].aff_y - map->low_y;
			s[i][j].aff_c = ft_color_pick(*map, env->var_color, &(s[i][j]));
		}
}

t_fdf	ft_proj_cal(t_fdf strc, t_env *e, int i, int j)
{
	if ((e->proj_type == 0) && (strc.x >= 0))
	{
		strc.aff_x = ((strc.x * 100 + (10 * strc.z)) * e->v_map.ecart) / 100;
		strc.aff_y = ((strc.y * 100 - (10 * strc.z)) * e->v_map.ecart) / 100;
	}
	else if (strc.x >= 0)
	{
		strc.aff_x = 0.71 * (strc.x - strc.y) * -e->v_map.ecart;
		strc.aff_y = (2 * strc.z - (strc.y + strc.x)) * 0.41 * -e->v_map.ecart;
	}
	if (strc.aff_x > e->v_map.max_x || (j == 0 && i == 0))
		e->v_map.max_x = strc.aff_x;
	if (strc.aff_x < e->v_map.low_x || (j == 0 && i == 0))
		e->v_map.low_x = strc.aff_x;
	if (strc.aff_y > e->v_map.max_y || (j == 0 && i == 0))
		e->v_map.max_y = strc.aff_y;
	if (strc.aff_y < e->v_map.low_y || (j == 0 && i == 0))
		e->v_map.low_y = strc.aff_y;
	if (strc.z > e->v_map.max_z || (j == 0 && i == 0))
		e->v_map.max_z = strc.z;
	if (strc.z < e->v_map.low_z || (j == 0 && i == 0))
		e->v_map.low_z = strc.z;
	return (strc);
}
