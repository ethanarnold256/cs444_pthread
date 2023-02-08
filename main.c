#include <stdlib.h>
#include <stdio.h>

struct matrix {
	int row;
	int col;
	int ** data;
};

// allocates matrix
struct matrix * malloc_matrix(int row, int col) {
	int ** data = malloc(row * sizeof(int));
	for (int r = 0; r < row; r++) {
		data[r] = malloc(col * sizeof(int));
	}
	struct matrix * matrix = malloc(sizeof(struct matrix));
	matrix->row = row;
	matrix->col = col;
	matrix->data = data;
	return matrix;
}

// gets user input
struct matrix * scanf_matrix() {
	int row, col;
	char c;
	printf("Please insert shape of matrix (nxm): ");
	while(scanf("%dx%d", &row, &col) != 2) {
		printf("ERROR: Invalid format.\nPlease retry: ");
		while((c = getchar()) != '\n' && c != EOF); // flush input
	}
	return malloc_matrix(row, col);
}

int main() {
	printf("You will be prompted to input the shape of two matrices below.\n");
	struct matrix * m1;
	struct matrix * m2;
	do {
	} while (m1->col != m2-> row);
	return 0;
}
