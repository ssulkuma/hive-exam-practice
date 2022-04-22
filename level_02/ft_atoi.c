/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/
/*
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str);
*/
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	index;

	index = 0;
	sign = 1;
	result = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n' || str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if ((str[index] == '-' && str[index + 1] == '-') || (str[index] == '-' && str[index + 1] == '+'))
		return (0);
	if ((str[index] == '+' && str[index + 1] == '-') || (str[index] == '+' && str[index + 1] == '+'))
		return (0);
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	printf("%s%d\n", "ATOI ", atoi("42"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("42"));
	printf("%s%d\n", "ATOI ", atoi("-42"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("-42"));
	printf("%s%d\n", "ATOI ", atoi("123456789"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("123456789"));
	printf("%s%d\n", "ATOI ", atoi("1 2 3 4 5"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("1 2 3 4 5"));
	printf("%s%d\n", "ATOI ", atoi("abc"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("abc"));
	printf("%s%d\n", "ATOI ", atoi(""));
	printf("%s%d\n", "FT_ATOI ", ft_atoi(""));
	printf("%s%d\n", "ATOI ", atoi("++123"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("++123"));
	printf("%s%d\n", "ATOI ", atoi("123-+45"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("123-+45"));
	printf("%s%d\n", "ATOI ", atoi("		1  2"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("		1  2"));
	printf("%s%d\n", "ATOI ", atoi("123abc45"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("123abc45"));
	printf("%s%d\n", "ATOI ", atoi("2147483647"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("2147483647"));
	printf("%s%d\n", "ATOI ", atoi("-2147483648"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("-2147483648"));
	printf("%s%d\n", "ATOI ", atoi("+++++"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("+++++"));
	printf("%s%d\n", "ATOI ", atoi("123456789987654321"));
	printf("%s%d\n", "FT_ATOI ", ft_atoi("123456789987654321"));
	return (0);
}
*/
