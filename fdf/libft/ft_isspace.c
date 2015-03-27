#
#
#

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v'
	|| c == '\f')
		return (0);
	return (42);
}
