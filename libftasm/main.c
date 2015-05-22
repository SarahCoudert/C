# include <stdio.h>

int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		main(void)
{
	printf("\nft_isdigit is supposed to return 1 if its first argument is an ascii \ncharacter who is representing a number. If not, it returns 0 :\n\n");
	printf("ft_isdigit with 0 : %d \n", ft_isdigit(0));
	printf("ft_isdigit with '0' : %d \n", ft_isdigit('0'));
	printf("ft_isdigit with 'a' : %d \n", ft_isdigit('a'));
	printf("\nft_isalnum is supposed to return 1 if its first argument is an ascii \ncharacter who is representing a number or a letter. If not, it returns 0 :\n\n");
	printf("ft_isalnum with 255 : %d \n", ft_isalnum(255));
	printf("ft_isalnum with '0' : %d \n", ft_isalnum('0'));
	printf("ft_isalnum with 'a' : %d \n", ft_isalnum('a'));
	printf("\nft_isalpha is supposed to return 1 if its first argument is an ascii \ncharacter who is representing a letter. If not, it returns 0 :\n\n");
	printf("ft_isalpha with '9' : %d \n", ft_isalpha('9'));
	printf("ft_isalpha with 'Z' : %d \n", ft_isalpha('Z'));
	printf("ft_isalpha with 'a' : %d \n", ft_isalpha('a'));
	printf("ft_isalpha with 255 : %d \n", ft_isalpha(255));
	printf("\nft_tolower is supposed to return a lower letter if an upper letter is sent \n If its not, it returns the character :\n\n");
	printf("ft_tolower with '9' : %c \n", ft_tolower('9'));
	printf("ft_tolower with 'Z' : %c \n", ft_tolower('Z'));
	printf("ft_tolower with 'a' : %c \n", ft_tolower('a'));
	printf("\nft_toupper is supposed to return an upper letter if a lower letter is sent \n If its not, it returns the character :\n\n");
	printf("ft_toupper with '9' : %c \n", ft_toupper('9'));
	printf("ft_toupper with 'Z' : %c \n", ft_toupper('Z'));
	printf("ft_toupper with 'a' : %c \n", ft_toupper('a'));
	return (0);
}
