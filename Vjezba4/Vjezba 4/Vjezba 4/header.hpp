#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <random>
using namespace std;

/*Napisati funkciju koja broji koliko pojavljivanja danog
podstringa ima u stringu koristeći funkcije standardne biblioteke.*/

unsigned cnt_substr(string& s, string& sub) {
	unsigned cnt = 0;
	size_t fnd = s.find(sub);
	if (fnd == string::npos)
		return 0;
	while (fnd != string::npos) {
		fnd = s.find(sub, fnd + 1);
		cnt++;
	}
	return cnt;
}
/*Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova,
svaki string preokrene te sortira vektor po preokrenutim stringovima*/

void string_vector_sort(vector<string>& vs) {
	string s;
	cout << "Unesite tri stringa:" << endl;
	int i = 0;
	while (i < 3) {
		cin >> s;
		reverse(s.begin(), s.end());
		vs.push_back(s);
		i++;
	}
	sort(vs.begin(), vs.end());
	return;
}
/*Učitati string koji predstavlja rečenicu. Napisati funkciju koja iz stringa izbacuje
sve praznine koje se nalaze ispred znakova interpunkcije i dodaje praznine nakon
znaka interpunkcije ako nedostaju.
Primjer: Za rečenicu ”Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .”,
Ispravna rečenica glasi: ”Ja bih, ako ikako mogu, ovu recenicu napisala ispravno.”.
*/
bool interpunction(char ch) {
	if (ch == '.' || ch == '?' || ch == '!' || ch ==',' || ch==';' || ch==':')
		return true;
	return false;
}
void correct_sentence(string& s) {
	string::iterator it = s.begin();
	if (*it == string::npos)
		cout << "Nema odgovarajuceg rezultata." << endl;
	else {
		s.push_back(' ');
		for (it; it != s.end();it++) {
			if (interpunction(*it)) {
				if (*(it + 1) != ' ') {
					s.insert(it + 1, ' ');
				}
				if (*(it-1) == ' ') {
					s.erase(it-1);
				}
			}
		}
	}
}
/*Napisati funkciju koji prevodi engleske rečenice na pig latin jezik. Pravila su sljedeća:
(a) ako riječ počinje samoglasnikom dopisuje se hay na kraj riječi,
(b) inače, svi suglasnici s početka riječi prebacuju se na kraj te se na kraju riječi
dopisuje ay.
Rečenice treba spremiti u vector, a zatim prevesti slučajno odabranu rečenicu iz
vektora.
Primjer: ”What time is it?” prevodi se kao ”atwhay imetay ishay ithay?”*/
bool interpunction_and_spc(char ch) {
	if (ch == '.' || ch == '?' || ch == '!' || ch == ',' || ch == ';' || ch == ':' || ch==' ')
		return true;
	return false;
}
bool isVowel(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		return true;
	return false;
}
void pig_latin(string& s) {
	size_t fnd = s.find_first_of(" ,.:;?!");
	size_t index = 0;
	while (fnd != string::npos) {
		if (isVowel(s.at(index))) {
			s.insert(fnd, "hay");
			fnd += 3;
			index = fnd + 1;
			fnd = s.find_first_of(" ,.:;?!", fnd + 1);
		}
		else {
			int cnt = 0;
			while (isVowel(s.at(index)) == false) {
				char ch = s.at(index);
				s.insert(fnd, 1, ch);
				cnt++;
				index++;
				fnd++;
			}
			s.erase(index - cnt, cnt);
			s.insert(fnd - cnt, "ay");
			if (cnt < 2)
				fnd = fnd + 1;
			index = fnd + 1;
			fnd = s.find_first_of(" ,.:;?!", fnd + 1);
		}
	}	
}
void pig_latin2(string& s) {
	string::iterator it = s.begin(), idx = s.begin();
	s.push_back(' ');
	for (it; it != s.end(); it++) {
		if (interpunction_and_spc(*it)) {
			if (isVowel(*idx)) {
				s.insert(it, 'hay');
				it += 3;
				idx = it + 1;
			}
			else {
				idx = it + 1;
				int cnt = 0;
				while (!isVowel(*idx)) {
					char ch = *idx;
					s.insert(it, 1, ch);
					cnt++;
					idx++;
					it++;
				}
				s.erase(idx - cnt, idx);
				s.insert(it - cnt, 'ay');
				if (cnt < 2)
					it+=1;
				idx = it + 1;

			}

		}
	}
}
/*Napisati program u kojem korisnik unosi binarne znamenke (0 i 1) i sprema ih u
container. Unosu je kraj kad korisnik unese vrijednost koja ne predstavlja binarnu
znamenku. Nakon toga napisati funkciju stuffing_bit koja primjeni bit stuffing
algoritam na container. Bit stuffing je tehnika koja se koristi u HDLC protokolima
za prijenos podataka u kojima je početak i završetak paketa određen sa nizom bitova
01111110. Da se ne bi sadržaj paketa brkao sa stop-bitovima, potrebno je nakon
svakog niza od pet jedinica umetnuti jednu nulu.
Primjer: za uneseni niz bitova
00111011111110001111111011
rezultat je
0011101111101100011111011011.*/

void stuffing_bit(vector<int>& v) {
	vector<int>::iterator it;
	int cnt = 0;
	for (it = v.begin(); it != v.end() - 1; it++) {
		if (*it == 1 && *(it + 1) == 1 && cnt < 5)
			cnt++;
		else
			cnt = 0;
		if (cnt == 5) {
			*(it + 1) = 0;
			cnt = 0;
		}
	}
}
void unstuffing_bit(vector<int>& v) {
	vector<int>::iterator it;
	int cnt = 0;
	for (it = v.begin(); it != v.end() - 1; it++) {
		if (*it == 0)
			cnt = 0;
		if (*it == 1 && *(it + 1) == 1 && cnt < 5)
			cnt++;
		if (*it == 1 && *(it + 1) == 0 && cnt == 4) {
			*(it + 1) = 1;
			cnt = 0;
		}
	}
}
