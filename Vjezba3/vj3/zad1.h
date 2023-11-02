#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void new_vector(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
	vector<int>::iterator it;
	for (it = v1.begin(); it != v1.end(); it++) {
		int cnt;
		cnt = count(v2.begin(), v2.end(), *it);
		if (!cnt)
			v3.push_back(*it);
	}
}
void vec_insert(vector<int>& v, int n) {
	v.reserve(n);
}
void print_vector(vector<int>& v) {
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void vector_intervals(vector<int>& v, int low, int high) {
	int num;
	cin >> num;
	if (num<low || num>high) {
		cout << "Broj nije u zadanom intervalu" << endl;
	}
	while (num >= low && num <= high) {
		v.push_back(num);
		cin >> num;
	}
	cout << "Broj nije u zadanom intervalu" << endl;
}
void zero_sum(vector<int>& v) {
	sort(v.begin(), v.end());
	vector<int>::iterator it = min_element(v.begin(), v.end());
	v.insert(it, 0);
	it = v.begin();
	int sum = 0;
	for (it; it != v.end(); it++) {
		sum += *it;
	}
	v.push_back(sum);
}

void remove_num(vector<int>& v, int idx) {
	vector<int>::iterator it = v.begin() + idx;
	v.erase(it);
}
