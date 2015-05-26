# include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_bzero(char *s, int size);
char	*ft_strcat(char *s, char *s2);
void	ft_puts(char *s);

char	*fill_string(char *s, int l)
{
	static int k = 0;
	int	i;
	int	j;

	j = 0;
	if (s == NULL)
		s = (char*)malloc(l);
	i = 0;
	while (i < 26 && i < l)
	{
		if (k % 2 == 0)
			s[i] = 'a' + i;
		else
			s[i] = '0' + i;
		i++;
		j++;
	}
	s[i] = '\0';
	k++;
	return (s);
}

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

void	test_bzero(char *(*bz)(char*, int), char *name, int l)
{
	char	*s;
	int		i;

	s = NULL;
	i = 0;
	s = fill_string(s, l);
	printf("\n\033[36mTest: [ft_%s] : [%s]\033[00m\n", name, s);
	s = (*bz)(s, l);
	while (i < l)
	{
		if (s[i] != '\0')
		{
			printf("\033[31mError: ft_%s of s[%d] = %d instead of 0\033[00m\n", name, i, s[i]);
			free (s);
			return ;
		}
		i++;
	}
	printf("\033[36m[%s] -> \033[32m[OK]\033[00m\n", name);
	free (s);
}

void	test_strcat(char *(*sct)(char *, char *), char *name)
{
	char *s2;
	char *s3;
	char *s;

	s = (char*)malloc(50);
	s2 = (char*)malloc(50);
	s3 = (char*)malloc(50);
	strcpy(s,"BON\0");
	strcpy(s + 4, "coucoujesuislapourmettrelamerde");
	strcpy(s3,"BON\0");
	strcpy(s3 + 4, "coucoujesuislapourmettrelamerde");
	strcpy(s2,"JOUR\0");
	strcpy(s2 + 5, "oui je suis la pour t'emmerder");
	printf("\n\033[36mTest: [ft_%s] : [%s] [%s]\033[00m\n", name, s, s2);
	printf("\033[36mft_trcat return : %s\nstrcat return : %s\n\033[00m", (*sct)(s, s2), strcat(s3, s2));
	printf("\033[36m[%s] -> \033[32m[OK] : [%s]\033[00m\n", name, s);
	free(s);
	free(s2);
	free(s3);
}

int		main(void)
{
	test_is(isdigit, ft_isdigit, "isdigit", 0);
	test_is(isalnum, ft_isalnum, "isalnum", 0);
	test_is(isalpha, ft_isalpha, "isalpha", 0);
	test_is(isascii, ft_isascii, "isascii", 0);
	test_is(toupper, ft_toupper, "toupper", 0);
	test_is(tolower, ft_tolower, "tolower", 0);
	test_bzero(ft_bzero, "bzero", 10);
	test_strcat(ft_strcat, "strcat");
	ft_puts("Bonjour");
	char	*s;
	s = NULL;
	ft_puts(s);
	return (0);
}
