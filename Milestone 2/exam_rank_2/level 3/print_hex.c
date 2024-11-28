
#include <unistd.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

// ascii to integer entire number (not iterating through)
int atoi(char *str) {
	int m = 0;
	int result = 0;
	while(str[m]) {
		result = result * 10 + str[m] - '0';
		m++;
	}
	return (result);
}

void print_hex(int m) {
	char hex[] = "0123456789abcdef";
	if (m >= 16)
		print_hex(m / 16);
	ft_putchar(hex[m % 16]);
	
}

int main(int argc, char **argv) {
	if (argc == 2) {
		print_hex(atoi(argv[1]));
	}
	ft_putchar('\n');
	return 0;
}