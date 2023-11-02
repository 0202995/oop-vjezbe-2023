#include <iostream>
#include <random>
using namespace std;
void min_max(int* niz, int& max, int& min, int n) {
	max = min = niz[0];
	for (int i = 1, j = 1; i < n; i++, j++) {
		if (niz[i] > max)
			max = niz[i];
		if (niz[i] < min)
			min = niz[i];
	}

}
// Napisati funkciju koja vraæa referencu na neki element niza. 
// Koristeæi povratnu vrijednost funkcije kao lvalue uveæajte i-ti element niza za jedan.
int& increase(int* niz, int idx) {
	return niz[idx];
}
struct Vector {
	int* niz;
	int size, capacity;

	void vector_new(int size) { int* niz = new int[size]; size = 0; capacity = size; }
	void vector_delete() { delete niz; }
	void vector_push_back(int num) {
		if (size == capacity) {
			capacity *= 2;
			int* nniz = new int[capacity];
			for (int i = 0; i < (capacity-1); i++) {
				nniz[i] = niz[i];
			}
			delete[] niz;
			niz = nniz;
			niz[size] = num;
			size += 1;
		}
	}
	void vector_pop_back() {
		size -= 1;
	}
	int& vector_front() {
		return niz[0];
	}
	int& vector_back() {
		return niz[size-1];
	}
	int vector_size() {
		return size;
	}
	void print_vector() {
		for (int i = 0; i < size; i++) {
			cout << niz[i] << " ";
		}
		cout << endl;
	}

};


struct Matrix {
	float** matrix;
	int rows, cols;
	void insert_matrix(int m, int n) {
		matrix = new float* [m];
		for (int i = 0; i < m; i++)
			matrix[i] = new float [n];
		rows = m; cols = n;
	}
	void insert_rnd_num(int a, int b, int r, int c) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				matrix = new float* [r];
				for (int i = 0; i < r; i++)
					matrix[i] = new float[c];
				rows = r; cols = c;

				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						random_device rd;
						mt19937 rng(rd());
						uniform_real_distribution<float> uni(a, b);
						float rnd = uni(rng);
						matrix[i][j] = rnd;
					}
				}

			}
		}
	}
	
	
};
Matrix* multiplicate(Matrix* m1, Matrix* m2) {
	if (m1->cols != m2->rows) {
		return NULL;
	}
	Matrix* m = new Matrix;
	m->matrix = new float* [m1->rows];
	for (int i = 0; i < m1->rows; i++)
		m->matrix[i] = new float[m2->cols];
	m->rows = m1->rows; m->cols = m2->cols;

	for (int i = 0; i < m1->rows; i++) {
		for (int j = 0; j < m2->cols; j++) {
			m->matrix[i][j] = 0;
			for (int k = 0; k < m2->rows; k++) {
				m->matrix[i][j] += m1->matrix[i][k] * m2->matrix[k][j];
			}

		}
	}
	return m;
}
Matrix* subtract(Matrix* m1, Matrix* m2) {
	if ((m1->cols != m2->cols) || (m1->rows != m2->rows)) {
		return NULL;
	}
	Matrix* m = new Matrix;
	m->matrix = new float* [m1->rows];
	for (int i = 0; i < m1->rows; i++)
		m->matrix[i] = new float[m1->cols];
	m->rows = m1->rows; m->cols = m1->cols;

	for (int i = 0; i < m1->rows; i++) {
		for (int j = 0; j < m1->cols; j++) {
			m->matrix[i][j] = m1->matrix[i][j] - m2->matrix[i][j];
		}
	}
	return m;
}
Matrix* add(Matrix* m1, Matrix* m2) {
	if ((m1->cols != m2->cols) || (m1->rows != m2->rows)) {
		return NULL;
	}
	Matrix* m = new Matrix;
	m->matrix = new float* [m1->rows];
	for (int i = 0; i < m1->rows; i++)
		m->matrix[i] = new float[m1->cols];
	m->rows = m1->rows; m->cols = m1->cols;

	for (int i = 0; i < m1->rows; i++) {
		for (int j = 0; j < m1->cols; j++) {
			m->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
		}
	}
	return m;
}
Matrix* transpose(Matrix* m1) {
	Matrix* m = new Matrix;
	m->matrix = new float* [m1->cols];
	for (int i = 0; i < m1->cols; i++)
		m->matrix[i] = new float[m1->rows];
	m->rows = m1->cols; m->cols = m1->rows;

	for (int i = 0; i < m1->cols; i++) {
		for (int j = 0; j < m1->rows; j++) {
			m->matrix[i][j] = m1->matrix[j][i];
		}
	}
	return m;

}
void print_matrix(Matrix*m) {
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			cout << m->matrix[i][j] << " ";
		}
		cout << endl;
	}
}

