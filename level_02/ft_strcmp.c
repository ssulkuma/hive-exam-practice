/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/
/*
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = (unsigned int)*s1 - (unsigned int)*s2;
	if (result == 0)
		return (0);
	else if (result < 0)
		return (-1);
	else
		return (1);
}
/*
int main(void)
{
	printf("%s%d\n", "STRCMP ", strcmp("abc", "abc"));
	printf("%s%d\n", "FT_STRCMP ", ft_strcmp("abc", "abc"));
	printf("%s%d\n", "STRCMP ", strcmp("alice in wonderland", "alice in wonderland"));
	printf("%s%d\n", "FT_STRCMP ", ft_strcmp("alice in wonderland", "alice in wonderland"));
	printf("%s%d\n", "STRCMP ", strcmp("CHESHIRE cat", "cheshire CAT"));
	printf("%s%d\n", "FT_STRCMP ", ft_strcmp("CHESHIRE cat", "cheshire CAT"));
	printf("%s%d\n", "STRCMP ", strcmp("98765", "12345"));
	printf("%s%d\n", "FT_STRCMP ", ft_strcmp("98765", "12345"));
	printf("%s%d\n", "STRCMP ", strcmp("", ""));
	printf("%s%d\n", "FT_STRCMP ", ft_strcmp("", ""));
	return (0);
}
*/
