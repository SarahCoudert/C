#include "stdlib.h"
#include "libft.h"

void	ft_double_tab_del(void **tab)
{
	int	j;

	j = 0;
	if (tab)
		{
		while (tab[j] != NULL)
		{
			free(tab[j]);
			j++;
		}
	}
	free(tab);
}
