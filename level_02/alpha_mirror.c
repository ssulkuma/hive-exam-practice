/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc == 2)
	{
		while (argv[1][index] != '\0')
		{
			if (argv[1][index] >= 'a' && argv[1][index] <= 'z')
				argv[1][index] = 'n' - (argv[1][index] - 'm');
			else if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
				argv[1][index] = 'N' - (argv[1][index] - 'M');
			write(1, &argv[1][index], 1);
			index++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
