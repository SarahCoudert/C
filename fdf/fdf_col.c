#include "fdf.h"

int		ft_col(t_trace t, t_env *e)
{
	int			p;
	t_color		verif;
	t_var_color	vcol;

	vcol = e->var_color;
	p = (((t.x2 - t.x1) * (t.x2 - t.x1)) + ((t.y2 - t.y1) * (t.y2 - t.y1)));
	if (vcol.degradee > 0)
		verif = ft_degradee(t.c1, t.c2, p, t.ref_prog);
	else
		verif.color = t.c1.color;
	if (verif.color < 0 || verif.color >= 0x1000000)
		verif.color = 0xFFFFFF;
	return (verif.color);
}

t_color	ft_inttocolstrc(int color)
{
	t_color		strc;

	strc.color = color;
	strc.red = color / (256 * 256);
	strc.green = (color / (256)) % 256;
	strc.blue = color % 256;
	return (strc);
}

t_color	ft_degradee(t_color c1, t_color c2, int p, int ref_prog)
{
	t_color		verif;
	int 		prog;
	int			v;

	v = 2;
	prog = ((p * 255) / ref_prog) / v;
	prog = prog * v;
	if ((((p * 255) / ref_prog) % v) > (v / 2))
		prog = prog + v;
	if (prog > 255)
		prog = 255;
	verif.red = ((c1.red * prog + c2.red * (255 - prog)) * 256 * 256);
	verif.green = (c1.green * prog + c2.green * (255 - prog)) * 256;
	verif.blue = (c1.blue * prog + c2.blue * (255 - prog));
	verif.color = (verif.blue) / 255 + verif.green / 255 + verif.red / 255;
	verif.blue /= 255;
	verif.red /= 255;
	verif.green /= 255;
	if (verif.color < 0 || verif.color > 0xFFFFFF)
		verif.color = 0xFFFFFF;
	return (verif);
}

t_color		ft_color_pick(t_v_map cst, t_var_color vcol, t_fdf *strc)
{
	strc->aff_c = ft_inttocolstrc(0xFFFFFF);
	if (vcol.col_flag >= 2)
	{
		if (strc->z < 0)
			strc->aff_c = ft_degradee(vcol.col_underground, vcol.col_ground,
					-(strc->z), -(cst.low_z));
		if (strc->z >= 0)
			strc->aff_c = ft_degradee(vcol.col_ground, vcol.col_high,
					strc->z, cst.max_z);
	}
	if (vcol.col_flag >= 1 && strc->color != -42)
		strc->aff_c = ft_inttocolstrc(strc->color);
	return (strc->aff_c);
}
