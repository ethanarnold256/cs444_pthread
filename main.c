#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct matrix {
	int ** data;
	int row;
	int col;
};

// argument for pthread
struct matrix_dotmult {
	struct matrix * m1;
	struct matrix * m2;
	struct matrix * m3;
	int row;
	int col;
};

// allocates matrix
struct matrix * malloc_matrix(int row, int col) {
	int ** data = malloc(row * sizeof(int*));
	for (int r = 0; r < row; r++) {
		data[r] = malloc(col * sizeof(int));
	}
	struct matrix * m = malloc(sizeof(struct matrix));
	m->data = data;
	m->row = row;
	m->col = col;
	return m;
}

// allocates dotmult struct for pthread
struct matrix_dotmult * malloc_matrix_dotmult(struct matrix * m1, struct matrix * m2, struct matrix * m3, int row, int col) {
	struct matrix_dotmult * m_dm = malloc(sizeof(struct matrix_dotmult));
	m_dm->m1 = m1;
	m_dm->m2 = m2;
	m_dm->m3 = m3;
	m_dm->row = row;
	m_dm->col = col;
	return m_dm;
}

// initializes matrix with random from 0 to cap
void rand_matrix(struct matrix * m, int cap) {
	for (int r = 0; r < m->row; r++) {
		for (int c = 0; c < m->col; c++) {
			m->data[r][c] = rand() % cap;
		}
	}
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

// prints matrix
void printf_matrix(struct matrix * m) {
	for (int r = 0; r < m->row; r++) {
		for (int c = 0; c < m->col; c++)
			printf("%2d ", m->data[r][c]);
		printf("\n");
	}
}

// multiply matching pairs
void * matrix_mult_thread(struct matrix_dotmult * m_dm) {
	int sum = 0;
	for (int c = 0; c < m_dm->m1->col; c++) 
		sum += m_dm->m1->data[row][c] * m_dm->m2->data[c][col];
	m_dm->m3->data[m_dm->row][m_dm->col] = sum;
}

// multiply matrices
struct matrix * matrix_dotmult(struct matrix * m1, struct matrix * m2) {
	struct matrix * m3 = malloc_matrix(m1->row, m2->col);
	for (int r = 0; r < m1->row; r++) {
		for (int c = 0; c < m2->col; c++) {

		}
	}
	return m3;
}

int main() {
	srand(time(NULL)); // initialize rand()
	printf("You will be prompted to input the shape of two matrices below.\n");
	struct matrix * m1; // matrix A
	struct matrix * m2; // matrix B
	struct matrix * m3; // product matrix
	bool error = true;
	do {
		m1 = scanf_matrix();
		m2 = scanf_matrix();
		error = (m1->col != m2-> row);
		if (error)
			printf("ERROR: Incompatible shape.\nPlease retry:\n");
	} while (error);
	rand_matrix(m1, 6);
	rand_matrix(m2, 6);
	printf("Here are your matrices:\n");
	printf("Matrix A:\n");
	printf_matrix(m1);
	printf("Matrix B:\n");
	printf_matrix(m2);
	printf("Dot product of A x B:\n");
	m3 = matrix_dotmult(m1, m2);
	return 0;
}
