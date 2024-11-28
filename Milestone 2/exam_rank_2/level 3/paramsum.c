
#include <unistd.h>

void ft_putnbr(int m) {
	char nbr;

	if (m >= 10)
		ft_putnbr(m / 10);
	nbr = (m % 10) + '0';
	write(1, &nbr, 1);
}

int	main(int argc, char **argv) {
	(void)argv;
	
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return 0;
}