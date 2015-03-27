#include "libft/includes/get_next_line.h"
#include "fdf.h"

int		main(int argc, const char **argv)
{
	t_env	e;

	if (fdf_strc_ini(&e, argc, argv) == NULL)
			return (-1);//ft_error("allocation failled")
	if (ft_restart(&e) == -1)
		return (-1);
	mlx_do_key_autorepeatoff(e.mlx);
	fdf_mlx(&e);
	return (0);
}

int		ft_restart(t_env *e)
{
	static int		x = 0;
	static int		y = 0;

	fdf_calcul_proj(e->mapping, e);
	if (x != e->v_map.win_x || y != e->v_map.win_y)
	{
		x = e->v_map.win_x;
		y = e->v_map.win_y;
		if (e->win != NULL)
			mlx_destroy_window(e->mlx, e->win);
		if ((e->win = mlx_new_window(e->mlx, x, y, "fdf")) == NULL)
			return (-1);//ft_error("allocation failled")
	}
	new_img(e);
	if (e->v_map.img_x == -4200 || e->v_map.img_y == -4200)
	{
		e->v_map.img_x = (e->v_map.win_x - e->v_map.max_x + e->v_map.low_x) / 2;
		e->v_map.img_y = (e->v_map.win_y - e->v_map.max_y + e->v_map.low_y) / 2;
	}
	fdf_trace(e->mapping, e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr, e->v_map.img_x,
			e->v_map.img_y);
	return (1);
}

t_env	*fdf_strc_ini(t_env *e, int argc, const char **argv)
{
	e->mapping = fdf_mapping(argc, argv);
	e->mlx = mlx_init();
	e->win = NULL;
	e->img = NULL;
	e->proj_type = 1;
	e->var_color.degradee = 20;
	e->var_color.col_flag = 2;
	e->var_color.col_high = ft_inttocolstrc(0xFF0000);
	e->var_color.col_ground = ft_inttocolstrc(0x00FF00);
	e->var_color.col_underground = ft_inttocolstrc(0x0000FF);
	e->v_map.win_x = 1000;
	e->v_map.win_y = 1000;
	e->v_map.ecart = -42;
	e->v_map.img_x = -4200;
	e->v_map.img_y = -4200;
	if (e->mlx == NULL || e->mapping == NULL)
		return (NULL);
	return (e);
}
