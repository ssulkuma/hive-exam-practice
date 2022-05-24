/*
Assignment name  : options
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of arguments which could be 
considered as options and writes on standard output a representation of those
options as groups of bytes followed by a newline.

An option is an argument that begins by a '-' and have multiple characters 
which could be : abcdefghijklmnopqrstuvwxyz

All options are stocked in a single int and each options represents a bit of that
int, and should be stocked like this : 

00000000 00000000 00000000 00000000
******zy xwvutsrq ponmlkji hgfedcba

Launch the program without arguments or with the '-h' flag activated must print
an usage on the standard output, as shown in the following examples.

A wrong option must print "Invalid Option" followd by a newline.

Examples :
$>./options
options: abcdefghijklmnopqrstuvwxyz
$>./options -abc -ijk
00000000 00000000 00000111 00000111
$>./options -z
00000010 00000000 00000000 00000000
$>./options -abc -hijk
options: abcdefghijklmnopqrstuvwxyz
$>./options -%
Invalid Option
*/

#include <unistd.h>

void	options(int argc, char **argv)
{
	char	letters[32] = {'*', '*', '*', '*', '*', '*', 'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
	int		bits[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			j++;
			if (argv[i][j -  1] == '-' && argv[i][j] == 'h')
			{
				write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
				return ;
			}
			else if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{
				while (argv[i][j] != '\0')
				{
					k = 0;
					while (letters[k] != '\0')
					{
						if (letters[k] == argv[i][j])
							bits[k] = 1;
						k++;
					}
					if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
						;
					else
					{
						write(1, "Invalid Option\n", 15);
						return ;
					}
					j++;
				}
			}
			else
			{
				write(1, "Invalid Option\n", 15);
				return ;
			}
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		if (bits[i] == 0)
			write(1, "0", 1);
		if (bits[i] == 1)
			write(1, "1", 1);
		if (i == 7 || i == 15 || i == 23)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		options(argc, argv);
	else
		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
	return (0);
}
