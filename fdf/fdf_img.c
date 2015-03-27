#include "fdf.h"

void			new_img(t_env *e)
{
	if (e->img != NULL)
	{
		if (e->img->ptr != NULL)
			mlx_destroy_image(e->mlx, e->img->ptr);
		free(e->img);
	}
	if ((e->img = (t_img*)malloc(sizeof(t_img))) == NULL)
		exit(0);//ft_error;
	e->img->width = (e->v_map.max_x - e->v_map.low_y) + 1;
	e->img->height = (e->v_map.max_y - e->v_map.low_y) + 1;
	e->img->ptr = mlx_new_image(e->mlx, e->img->width, e->img->height);
	e->img->data = mlx_get_data_addr(e->img->ptr, &e->img->bpp,
			&e->img->size_line, &e->img->endian);
}

//gerer l'endian

int				img_pixel_put(t_env *e, int x, int y, int color)
{
	t_img	*img;
	int		octets;
	int		k;

	img = e->img;
	octets = img->bpp / 8;
	k = img->size_line / octets;
	if ((x >= 0 && x < img->width) && (y >= 0 && y < img->height))
		ft_memcpy(&img->data[octets * (x + k * y)], &color, octets);
	else
		return (-1);
	e->img = img;
	return (1);
}
