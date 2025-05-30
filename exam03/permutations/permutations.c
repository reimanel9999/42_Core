
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

static int	next_permuta(char *str, int len)
{
	int	i;
	int	j;

	i = len - 2;
	j = i + 1;
	while (i >= 0 && str[i] > str[i + 1])
		i--;
	if (i < 0)
		return 0;
	while (str[i] >= str[j])
		j--;
	swap(&str[i], &str[j]);
	int right;
	int left;
	right = len - 1;
	left = i + 1;
	while (left < right)
	{
		swap(&str[left], &str[right]);
		left++;
		right--;
	}
	return 1;
}

int main(int argc, char **argv)
{
    char    *str;
    int     m;

    str = argv[1];
    m = strlen(str);
    if (argc != 2)
        return (1);
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (str[i] > str[j])
                swap(&str[i], &str[j]);
        }
    }
    do
        puts(str);
	while (next_permuta(str, m));
    return (0);
}








