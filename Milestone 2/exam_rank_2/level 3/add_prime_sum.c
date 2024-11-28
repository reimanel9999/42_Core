
#include <unistd.h>

int atoi(char *str) {
	int result = 0;

	while (*str) {
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

void ft_putnbr(int m) {
	char nbr;
	
	if (m >= 10)
		ft_putnbr(m / 10);
	nbr = m % 10 + '0';
	write(1, &nbr, 1);
}

int is_prime(int num) {
	int m = 2;
	if (num <= 1)
		return 0;
	while (m * m <= num) {
		if (num % m == 0)
			return 0;
		m++;
	}
	return 1;
}

int main(int argc, char **argv) {
	int nbr;
	int sum = 0;
	
	if (argc == 2) {
		nbr = atoi(argv[1]);
		while (nbr > 0) {
			if (is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		ft_putnbr(sum);
	}
	if (argc != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return 0;
}