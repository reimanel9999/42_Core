
#include <unistd.h>

void capitalize(char *str) {
	int m = 0;

	if (str[m] >= 'a' && str[m] <= 'z')
		str[m] -= 32;
	write(1, &str[m], 1);
	while (str[++m]) {
		if (str[m] >= 'A' && str[m] <= 'Z')
			str[m] += 32;
		if (str[m] >= 'a' && str[m] <= 'z' && (str[m-1] == ' ' || str[m-1] == '	'))
			str[m] -= 32;
		write(1, &str[m], 1);
	}
	write(1, "\n", 1);
}

int main (int argc, char **argv) {
	int m = 1;
	
	if (argc > 1) {
		while (m < argc) {
			capitalize(argv[m]);
			m++;
		}
	}
	else 
		write(1, "\n", 1);
	return 0;
}