#include <stdlib.h>
#include <stdio.h>

void Init(size_t N, size_t parent[N]) {
	for (int k = 0; k < N; ++k) {
		parent[k] = SIZE_MAX;
	}
}

size_t Find(size_t parent[], size_t index) {
	size_t current_index = index;
	size_t current_value = parent[current_index];

	while (current_value != SIZE_MAX) {
		current_index = current_value;
		current_value = parent[current_index];
	}

	return current_index;
}

void FindReplace(size_t parent[], size_t index, size_t value) {
	size_t current_index = index;
	size_t current_value;

	do {
		current_value = parent[current_index];
		parent[current_index] = value;
		current_index = current_value;
	} while (current_value != SIZE_MAX);
}

size_t FindCompress(size_t parent[], size_t index) {
	size_t root = Find(parent, index);
	size_t current_index = index;
	size_t current_value = parent[current_index];

	while (current_value != SIZE_MAX) {
		parent[current_index] = root;
		current_index = current_value;
		current_value = parent[current_index];
	}

	return root;
}

void Union(size_t parent[], size_t elm1, size_t elm2) {
	size_t root = FindCompress(parent, elm1);
	FindReplace(parent, elm2, root);
}

int main(int argc, char* argv[argc+1]) {
	size_t N = strtoul(argv[1], 0, 10); /* size of the set */
	size_t parent[N]; /* index table */

	Init(N, parent);

	if (N >= 8) {
		Union(parent, 0, 1);
		Union(parent, 1, 4);
		Union(parent, 2, 3);
		Union(parent, 0, 5);
		Union(parent, 1, 7);
	}

	for (size_t i = 0; i < N; ++i) {
		printf("%zu:\t%zu\n", i, parent[i]);
	}
}
