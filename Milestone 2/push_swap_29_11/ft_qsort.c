#include "push_swap.h"

void	ft_swap(void *a, void *b, size_t size) {
	char	temp[size];
	char	*swap_a;
	char	*swap_b;
	size_t	m;
	
	swap_a = (char *)a;
	swap_b = (char *)b;
	m = 0;
	while (m < size) {
		temp[m] = swap_a[m];
		swap_a[m] = swap_b[m];
		swap_b[m] = temp[m];
		m++;
	}
}

size_t partition(void *base, size_t size, size_t low, size_t high, int (*compar)(const void *, const void *)) {
	char *array;
	void *pivot;
	size_t m;
	size_t n;

	array = (char *)base;
	pivot = array + high * size;
	m = low;
	n = low;
	while (n < high) {
		if (compar(array + n * size, pivot) < 0) {
			ft_swap(array + m * size, array + n * size, size);
			m++;
		}
		n++;
	}
	ft_swap(array + m * size, array + high * size, size);
	return m;
}

void quicksort(void *base, size_t size, size_t low, size_t high, int (*compar)(const void *, const void *)) {
	if (low < high) {
		size_t temp; 
		temp = partition(base, size, low, high, compar);
		if (temp > 0) quicksort(base, size, low, temp - 1, compar);  // Avoid underflow
		quicksort(base, size, temp + 1, high, compar);
	}
}

void ft_qsort(void *base, size_t len_num, size_t size, int (*compar)(const void *, const void *)) {
	if (len_num > 1) {
		quicksort(base, size, 0, len_num - 1, compar);
	}
}

// Comparison function for integers
int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

// // Example usage
// int main() {
// 	int arr[] = {10, 7, 8, 9, 1, 5};
// 	size_t n = sizeof(arr) / sizeof(arr[0]);

// 	ft_qsort(arr, n, sizeof(int), compare);

// 	printf("Sorted array: ");
// 	for (size_t i = 0; i < n; i++) {
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	return 0;
// }
