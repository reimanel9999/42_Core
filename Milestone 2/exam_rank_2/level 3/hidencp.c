
#include <unistd.h>

int find(char *s1, char *s2) {
	int m = 0;
	int n = 0;
	
	while (s2[n]) {
		if (s1[m] == s2[n])
			m++;
		n++;
	}
	if (s1[m] == '\0')
		return 1;
	return 0;
}

int main(int argc, char **argv) {
	if (argc == 3) {
		if (find(argv[1], argv[2]))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return 0;
}