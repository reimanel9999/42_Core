#include <unistd.h>

int atoi(char *str) {
	int result = 0;
	int m = 0;
	while (str[m] == ' ' || str[m] == '	')
		m++;
	while (str[m] >= '0' && str[m] <= '9')
	{
		result = result * 10 + str[m] - '0';
		m++;
	}
	return (result);
}

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_putnbr(int m) {
	char nbr;
	if (m >= 10)
		ft_putnbr(m / 10);
	ft_putchar(m % 10 + '0');
	
}


int main(int argc, char **argv) {
	int m;
	int nbr;

	if (argc == 2) {
		m = 1;
		nbr = atoi(argv[1]);
		while (m <= 9 && nbr <= 238609183) {
			ft_putnbr(m);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(m * nbr);
			write(1, "\n", 1);
			m++;
		}
	}
	else 
		write(1, "\n", 1);
}