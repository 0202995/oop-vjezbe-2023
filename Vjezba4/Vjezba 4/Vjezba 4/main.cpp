#include "header.hpp"
int main(void) {
	/*string str = "strstrstrstr", substr = "str";
	cout << cnt_substr(str, substr) << endl;

	vector<string> vs;
	string_vector_sort(vs);
	for (int i = 0; i < size(vs); i++) {
		cout << vs[i] << " ";
	}
	cout << endl;*/

	string stc = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .";
	correct_sentence(stc);
	cout << stc << endl;

	string eng_stc = "what time is it?";
	pig_latin(eng_stc);
	cout << eng_stc << endl;
	return 0;
}