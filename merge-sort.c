#include <stdlib.h>
#include <stdio.h>

void merge(double arr[], double aux[], int start, int mid, int end) {
	for (size_t k = start; k <= end; ++k) {
		aux[k] = arr[k];
	}
	
	int i = start;
	int j = mid + 1;

	for (size_t k = start; k <= end; ++k) {
		if (i > mid) {
			arr[k] = aux[j];
			j = j + 1;
		} else if (j > end) {
			arr[k] = aux[i];
			i = i + 1;
		} else if (aux[j] < aux[i]) {
			arr[k] = aux[j];
			j = j + 1;
		} else {
			arr[k] = aux[i];
			i = i + 1;
		}
	}
}

void merge_sort(double arr[], double aux[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, aux, start, mid);
		merge_sort(arr, aux, mid+1, end);
		merge(arr, aux, start, mid, end);
	}
}

void test_sort(int n, double arr[n]) {
	int sorted = 1;
	for (size_t i = 0; i < n-1; ++i) {
		if (arr[i] > arr[i+1]) {
			printf("ERROR: not sorted\n");
			sorted = 0;
			break;
		}
	}
	if (sorted) {
		printf("Correctly sorted\n");
	}
}

int main(int argc, char* argv[argc+1]) {
	size_t n = argc-1;
	double arr[n];
	double aux[n];

	for (size_t i = 0; i < n; ++i) {
		arr[i] = strtod(argv[i+1], 0);
	}

	merge_sort(arr, aux, 0, n-1);

	for (size_t i = 0; i < n; ++i) {
		printf("%zu:\t%.2g\n", i, arr[i]);
	}

	test_sort(n, arr);

	return EXIT_SUCCESS;
}
