
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
	int nbr1;
	int nbr2;

	if (argc == 3) {
		if ((nbr1 = atoi(argv[1])) > 0 || (nbr2 = atoi(argv[2])) > 0) {		
			while (nbr1 != nbr2) {
				if (nbr1 > nbr2)
					nbr1 -= nbr2;
				else
					nbr2 -= nbr1;
			}
			printf("%d", nbr1);
		}
	}
	printf("\n");
	return 0;
}

// int main(int argc, char **argv) {
// 	int nbr1;
// 	int nbr2;

// 	if (argc == 3) {
// 		if ((nbr1 = atoi(argv[1])) > 0 || (nbr2 = atoi(argv[2])) > 0) {		
// 		while (nbr2 != 0) {
// 			unsigned int temp = nbr2;
// 			nbr2 = nbr1 % nbr2;
// 			nbr1 = temp;
// 		}
// 		printf("%d", nbr1);
// 	}
// 	}
// 	printf("\n");
// 	return 0;
// }