/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

void put_number(int number)
{
	char nb;

	nb = '0';
	if (number > 9)
	{
		put_number(number / 10);
		put_number(number % 10);
	}
	else
	{
		nb = number + '0';
		write(1, &nb, 1);
	}
}

int	simple_atoi(char *str)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	while (str[index] != '\0')
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	int	index;
	int	len;
	int	result;

	index = 1;
	len = 0;
	result = 0;
	if (argc == 2)
	{
		while (argv[1][len] != '\0')
			len++;
		while (index <= 9)
		{
			result = index * simple_atoi(argv[1]);
			put_number(index);
			write(1, " x ", 3);
			put_number(simple_atoi(argv[1]));
			write(1, " = ", 3);
			put_number(result);
			write(1, "\n", 1);
			index++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
