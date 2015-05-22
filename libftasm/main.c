# include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_bzero(char *s, int size);
char	*ft_strcat(char *s, char *s2);

void		test_is(int (*is)(int), int (*ft_is)(int), char *name, int d)
{
	int		i;
	int		j;

	i = -50;
	j = 0;
	printf("\n\033[36mTest: [ft_%s]\033[00m\n", name);
	while (i < 150)
	{
		if (ft_is(i) != is(i))
		{
			printf("\033[31mError: [%d]\n    Return: %s[%d] <> ft_%s[%d]\033[00m\n", i, name, is(i), name, ft_is(i));
			j++;
		}
		else if (d == 1)
			printf("[%d]: %s = [%d] <> ft_%s = [%d] -> [\033[32mOK\033[00m]\n", i, name, is(i), name, ft_is(i));
		i++;
	}
	if (j == 0)
		printf("\033[36m[%s] -> \033[32m[OK]\033[00m\n", name);
	else
		printf("\033[36m[%s] -> \033[31m[FAIL]\033[00m\n", name);
}

int		main(void)
{
	test_is(isdigit, ft_isdigit, "isdigit", 0);
	test_is(isalnum, ft_isalnum, "isalnum", 0);
	test_is(isalpha, ft_isalpha, "isalpha", 0);
	test_is(isascii, ft_isascii, "isascii", 0);
	test_is(toupper, ft_toupper, "toupper", 0);
	test_is(tolower, ft_tolower, "tolower", 0);
	int	i;
	char *s;

	s = (char*)malloc(27);
	i = 0;
	while (i < 26)
	{
		s[i] = 'a' + i;
		i++;
	}
	s[i] = '\0';
	printf("\nft_bzero is supposed to return a string fill with \'\\0\' :\n\n");
	printf("string before ft_bzero : \"%s\", \n", s);
	printf("and after : %s \n", ft_bzero(s, i));
	printf("we could test the value of s[26] : %d, \'\\0\' is supposed to be %d in ascii value\n", (int)s[26], '\0');
	printf("we could also test the value of s[0] : %d\n", (int)s[0]);
	printf("\nft_strcat is supposed to return a string which contains s1 plus s2 :\n");
	char *s2;

	s2 = (char*)malloc(27 - 15);
	i = 0;
	while (i < 15)
	{
		s[i] = 'a' + i;
		i++;
	}
	s[i] = '\0';
	int	j;

	j = 0;
	while (j + i < 26)
	{
		s2[j] = 'a' + i + j;
		j++;
	}
	s2[j] = '\0';
	printf("strings before strcat : %s and %s \n", s, s2);
	printf("and after : %s\n", ft_strcat(s, s2));
	return (0);
}
