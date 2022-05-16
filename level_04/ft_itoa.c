/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>
#include <stdio.h>

int		digit_count(int nbr)
{
	int		result;

	result = 0;
	if (nbr < 0)
	{
		nbr *= (-1);
		result++;
	}
	if (nbr > 9)
	{
		while (nbr != 0)
		{
			nbr /= 10;
			result++;
		}
	}
	else if (nbr <= 9 && nbr >= 0)
		result++;
	return (result);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		count;

	count = digit_count(nbr);
	result = (char *)malloc(sizeof(char) * count);
	if (!result)
		return (NULL);
	result[count] = '\0';
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return ("-2147483648\0");
		nbr *= (-1);
		result[0] = '-';
	}
	while (--count >= 0)
	{
		if (result[count] == '-')
			break;
		result[count] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int	main(void)
{
	printf("%d\n", -123456789);
	printf("%s\n", ft_itoa(-123456789));
	printf("%d\n", 123456789);
	printf("%s\n", ft_itoa(123456789));
	printf("%d\n", 2147483647);
	printf("%s\n", ft_itoa(2147483647));
	printf("%ld\n", -2147483648);
	printf("%s\n", ft_itoa(-2147483648));
	printf("%d\n", 0);
	printf("%s\n", ft_itoa(0));
	printf("%d\n", 42);
	printf("%s\n", ft_itoa(42));
	return (0);
}
