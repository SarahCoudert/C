# include "fdf.h"

int		main(void)
{
	t_color		col_1;
	t_color		col_2;
	t_color		ret_col;
	int			i;
	int			j;

	col_1 = ft_inttocolstrc(0x646464);
	col_2 = ft_inttocolstrc(0x000000);
	printf("col_1 ==> color: %d\tred: %d\tgreen: %d\tblue:%d\t\n", col_1.color, col_1.red, col_1.green, col_1.blue);
	printf("col_2 ==> color: %d\tred: %d\tgreen: %d\tblue:%d\t\n", col_2.color, col_2.red, col_2.green, col_2.blue);
	i = 0;
	j = 255;
	while (i <= j)
	{
		ret_col = ft_degradee(col_1, col_2, i, j);
		printf("ret_col ==> color: %d\tred: %d\tgreen: %d\tblue:%d\tprog = %d\tref_prog = %d\n", ret_col.color, ret_col.red / (256 * 256), ret_col.green / 256, ret_col.blue, i, j);
		i += 1;
	}
	return (0);
}
