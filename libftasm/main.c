# include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libfts.h"

char	*fill_string(char *s, int l)
{
	static int k = -1;
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
	printf("\n\033[36mTest: [ft_%s] with value from -50 to 150\033[00m\n", name);
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
	printf("\033[36mft_strcat return : %s\nstrcat return : %s\n\033[00m", (*sct)(s, s2), strcat(s3, s2));
	printf("\033[36m[%s] -> \033[32m[OK] : [%s]\033[00m\n", name, s);
	free(s);
	free(s2);
	free(s3);
}

void	test_strlen(size_t(*slen)(char*), char *name, int l)
{
	char *s;

	s = NULL;
	s = fill_string(s, l);
	printf("\n\033[36mTest: [ft_%s] : [%s]\033[00m\n", name, s);
	printf("\033[36mft_%s return : %lu\n%s return : %lu\n\033[00m",name, (*slen)(s), name, strlen(s));
	printf("\033[36m[%s] -> \033[32m[OK]\033[00m\n", name);
}

void	test_puts(void(*puts)(char*), char *name)
{
	char	*s;

	s = NULL;
	printf("\n\033[36mTest: [%s]\033[00m\n", name);
	(*puts)("I am testing myself, I am a big boy, yea ! >:D");
	(*puts)("\033[33mIn fact a lot of string here are display with ft_puts ! (This one for example)\033[00m");
	(*puts)("\033[36mTest with a null string\033[00m");
	(*puts)(s);
	printf("\033[36m[%s] -> [\033[32mOK]\033[00m]\n", name);
}

void	test_memcpy(char *name, int l)
{
	char	*s;
	char	*s2;

	s2 = NULL;
	s2 = fill_string(s2, l);
	s = NULL;
	s = (char*)malloc(l + 1);
	printf("\n\033[36mTest: [ft_%s] : [%s]\033[00m\n", name, s2);
	printf("\033[36mft_%s return : %s\n\033[00m",name, ft_memcpy(s, s2, l + 1));
	printf("\033[36m[%s] -> \033[32m[OK]\033[00m\n", name);

}

void	test_memset(void*(*mem)(void*, int, size_t), char *name, int len)
{
	char	*s;

	s = NULL;
	s = fill_string(s, len);
	printf("\n\033[36mTest: [ft_%s] : [%s]\033[00m\n", name, s);
	printf("\033[36mft_%s with '1' return : %s\n\033[00m",name, (char*)(*mem)(s, (int)'1', len));
	printf("\033[36m[ft_%s] -> \033[32m[OK]\033[00m\n", name);
}

void	test_strdup(char *name, int len)
{
	char	*s;

	s = NULL;
	s = fill_string(s, len);
	printf("\n\033[36mTest: [ft_%s] : [%s]\033[00m\n", name, s);
	printf("\033[36mft_%s return : %s\n\033[00m",name, ft_strdup(s));
	printf("\033[36m[ft_%s] -> \033[32m[OK]\033[00m\n", name);
}

int		main(void)
{
	ft_puts("\033[33m\n/!\\Change test_is last value from '0' to '1'\ndirectly in main if you want to see tests details./!\\\n\033[00m");
	test_is(isdigit, ft_isdigit, "isdigit", 0);
	test_is(isalnum, ft_isalnum, "isalnum", 0);
	test_is(isalpha, ft_isalpha, "isalpha", 0);
	test_is(isascii, ft_isascii, "isascii", 0);
	test_is(toupper, ft_toupper, "toupper", 0);
	test_is(tolower, ft_tolower, "tolower", 0);
	test_bzero(ft_bzero, "bzero", 10);
	test_strcat(ft_strcat, "strcat");
	test_puts(ft_puts, "ft_puts");
	test_strlen(ft_strlen, "strlen", 26);
	test_memset(ft_memset, "memset", 10);
	test_memcpy("memcpy", 26);
	test_strdup("strdup", 10);
	ft_puts("");
	return (0);
}
