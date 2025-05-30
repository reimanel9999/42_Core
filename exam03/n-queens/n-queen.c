
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void	print(int positions[1000], int q)
{
	int	i;
	char	c;
	i = 0;
	while (i < q)
	{
		c = '0' + positions[i];
		write(1, &c, 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	allow(int positions[1000], int row, int pos)
{
	int	m;
	m = 0;
	while (m < row)
	{
		if (positions[m] == pos \
				|| row - m == pos - positions[m] \
				|| row - m == positions[m] - pos)
			return 0;
		m++;
	}
	return 1;
}

static void	queen(int positions[1000], int q, int row)
{
	int pos;
	
	pos = 0;
	while (pos < q)
	{
		if(allow(positions, row, pos))
		{
			positions[row] = pos;
			if (row == q - 1)
				print(positions, q);
			else
				queen(positions, q, row + 1);
		}
		pos++;
	}
}


int main(int argc, char **argv)
{
	char *temp = argv[1];
	int m = atoi(temp);
	int positions[1000];

	if (argc != 2)
		return 1;
	queen(positions, m, 0);
	return 0;
}
	








