#include "zad1.h"
int main(void) {
	vector<int> v, v1, v2, v3;
	vec_insert(v1, 5);
	vec_insert(v2, 5);
	vector_intervals(v1, 0, 100);
	vector_intervals(v2, 0, 100);
	new_vector(v1, v2, v3);
	print_vector(v3);
	zero_sum(v3);
	print_vector(v3);
	remove_num(v3, 4);
	print_vector(v3);
	return 0;
}