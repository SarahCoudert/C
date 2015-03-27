#
#
#
#

#include "libft.h"

int		ft_hexatodeci(char *str)
{
	int		value;

	value = -42;
	str = ft_strtrim(str);
	while (*str)
	{
		if (*str == '0' && (*(++str) == 'X' || *str == 'x'))
		{
			str++;
			value = 0;
			while (((*str <= '9') && (*str >= '0'))
					|| ((*str >= 'A') && (*str <= 'Z'))
					|| ((*str >= 'a') && (*str <= 'z')))
			{
				value = value * 16;
				if (*str >= '0' && *str <= '9')
					value = (value + *str) - '0';
				if (*str >= 'A' && *str <= 'Z')
					value = ((value + *str) - 'A') + 10;
				if (*str >= 'a' && *str <= 'z')
					value = ((value + *str) - 'a') + 10;
				str++;
			}
			return (value);
		}
		else
			str++;
	}
	return (value);
}
