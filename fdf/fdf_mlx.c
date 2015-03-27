#include "fdf.h"
#include "keycode.h"

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	printf("key: %d\n", keycode);
	if (keycode == KEY_ESCAPE)
	{
		ft_double_tab_del((void**)e->mapping);
		mlx_destroy_image(e->mlx, e->img->ptr);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == NUM_PAD_PLUS || keycode == KEY_PLUS)
		e->v_map.ecart += 1;
	if (keycode == NUM_PAD_MOINS || keycode == KEY_MOINS)
		e->v_map.ecart -= 1;
	if (keycode == NUM_PAD_5)
	{
		e->v_map.img_x = -4200;
		e->v_map.img_y = -4200;
	}
	if (keycode == NUM_PAD_6)
		e->v_map.img_x += 5;
	if (keycode == NUM_PAD_4)
		e->v_map.img_x -= 5;
	if (keycode == NUM_PAD_2)
		e->v_map.img_y += 5;
	if (keycode == NUM_PAD_8)
		e->v_map.img_y -= 5;
	if (ft_restart(e) == -1)
		exit(0);//ft_error;
	printf("\ne->v_map.ecart : %d\n",e->v_map.ecart);
	printf("\ne->v_map.max_x : %f\n",e->v_map.max_x);
	printf("\ne->v_map.low_x : %f\n",e->v_map.low_x);
	printf("\ne->v_map.max_y : %f\n",e->v_map.max_y);
	printf("\ne->v_map.low_y : %f\n",e->v_map.low_y);
	printf("\ne->v_map.win_x : %d\n",e->v_map.win_x);
	printf("\ne->v_map.win_y : %d\n",e->v_map.win_y);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	(void)x;
	(void)y;
	(void)button;
	return (0);
}

int		expose_hook(t_env *e)
{
	if (ft_restart(e) == -1)
		exit(0);//ft_error;
	return (0);
}

t_env	fdf_mlx(t_env *env)
{
	mlx_key_hook(env->win, key_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (*env);
}
