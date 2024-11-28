
#include <unistd.h>
#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b) {
	int n;

	if (a == 0 || b == 0)
		return 0;
	if (a > b)
		n = a;
	else if (a < b)
		n = b;
	while (1) {
		if (n % a == 0 && n % b == 0)
			return n;
		n++;
	}
}

int main() {
    unsigned int a, b, result;
	a = 20;
	b = 6;
    // Calculate LCM
    result = lcm(a, b);

    // Output the result
    printf("The LCM of %u and %u is: %u\n", a, b, result);

    return 0;
}