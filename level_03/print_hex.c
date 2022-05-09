/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

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
	int number;
	int index;
	char base[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	char hex[6];

	if (argc == 2)
	{
		number = simple_atoi(argv[1]);
		if (number >= 16)
		{
			index = 0;
			while (number != 0)
			{
				hex[index] = base[number % 16];
				number = number / 16;
				index++;
			}
			index -= 1;
			while (index >= 0)
			{
				write(1, &hex[index], 1);
				index--;
			}
		}
		else
			write(1, &base[number], 1);
	}
	write(1, "\n", 1);
	return (0);
}
