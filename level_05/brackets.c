/*
Assignment name  : brackets 
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline 
if the expression is correctly bracketed, otherwise it prints "Error" followed by
a newline.

Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' 
and ']'and braces '{' and '}'. Every other symbols are simply ignored.

An opening bracket must always be closed by the good closing bracket in the 
correct order. A string which not contains any bracket is considered as a 
correctly bracketed string.

If there is no arguments, the program must print only a newline.

Examples :

$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
$>
*/

#include <unistd.h>

int match(char a, char *str, int index)
{
	if (a == ')')
	{
		while (index >= 0)
		{
			if (str[index] == '(')
				return (index);
			else if (str[index] == '{' || str[index] == '[')
				return (-1);
			index--;
		}
	}
	if (a == '}')
	{
		while (index >= 0)
		{
			if (str[index] == '{')
				return (index);
			else if (str[index] == '(' || str[index] == '[')
				return (-1);
			index--;
		}
	}
	if (a == ']')
	{
		while (index >= 0)
		{
			if (str[index] == '[')
				return (index);
			else if (str[index] == '{' || str[index] == '(')
				return (-1);
			index--;
		}
	}
	return (-1);
}

int brackets(char *str)
{
	char	bracket;
	int		index;
	int		result;
	int		closing;
	int		check;

	index = 0;
	result = 0;
	closing = 1;
	check = 0;
	if (str[index] == '\0')
		return (1);
	while (str[index] != '\0')
	{
		if (str[index] == ')' || str[index] == '}' || str[index] == ']' || str[index] == '(' || str[index] == '{' || str[index] == '[')
			check = 1;
		index++;
	}
	if (!check)
		return (1);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ')' || str[index] == '}' || str[index] == ']')
		{
			bracket = str[index];
			closing = 0;
			result = match(bracket, str, index);
			if (result >= 0)
				str[result] = 'A';
			else
				return (0);
		}
		index++;
	}
	if (closing)
		return (0);
	else
		return (1);
}

int main(int argc, char **argv)
{
	int		index;

	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			if (brackets(argv[index]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			index++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
