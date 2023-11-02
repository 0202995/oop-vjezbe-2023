#include "Vj2.hpp"	

int main(void) {
	/*int niz[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(niz) / sizeof(int), max, min;
	min_max(niz, max, min, n);
	cout << max << min << endl;
	niz[2] = increase(niz, 2) + 1;
	cout << niz[2] << endl;*/
	/*Vector v{};
	v.vector_new(4);
	v.vector_push_back(1);
	v.vector_push_back(2);
	v.vector_push_back(3);
	v.vector_pop_back();
	v.print_vector();*/
	Matrix m1, *m2, *mlt;
	//m.insert_matrix(2, 4);
	m1.insert_rnd_num(1, 20, 3, 3);
	print_matrix(&m1);
	cout << endl;
	//m2.insert_rnd_num(1, 20, 3, 4);
	//mlt = multiplicate(&m1, &m2);
	m2 = transpose(&m1);
	print_matrix(m2);
	
	return 0;
}