/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/
/*
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);
*/
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		index;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		dup[index] = src[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
/*
int	main(void)
{
	printf("%s%s\n", "STRDUP ", strdup("ALICE ALICE ALICE"));
	printf("%s%s\n", "FT_STRDUP ", ft_strdup("ALICE ALICE ALICE"));
	printf("%s%s\n", "STRDUP ", strdup("wonderland"));
	printf("%s%s\n", "FT_STRDUP ", ft_strdup("wonderland"));
	printf("%s%s\n", "STRDUP ", strdup(""));
	printf("%s%s\n", "FT_STRDUP ", ft_strdup(""));
	printf("%s%s\n", "STRDUP ", strdup("123456789"));
	printf("%s%s\n", "FT_STRDUP ", ft_strdup("123456789"));
	return (0);
}
*/
