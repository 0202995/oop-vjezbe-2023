#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono> 
using namespace std;

class Karta {
	unsigned broj;
	string zog;
public:
	Karta() { broj = 0; zog = ""; }
	void set_num(unsigned num) { broj = num; };
	void set_zog(string s) { zog = s; };
	void print_card(){ cout << broj << " " << zog << " " << endl; }
	void get_num_zog(unsigned* num, string& str) { *num = broj; str = zog; }
};
class Igrac {
	unsigned bodovi;
	string ime = "";
	vector<Karta> vruka;
	Karta k;
public:
	Igrac() { bodovi = 0; ime = ""; vruka.reserve(10); }
	void get_num_players(unsigned* num);
	void set_name_plyr(string s) { ime = s; }
	void fill_hand(Karta& k) {	vruka.push_back(k);	}
	void print_igrac_ruka();
	void akuza();
	void napolitana();
};
class Mac {
	Karta k;
	Igrac *ig;
	vector<Karta> mac_karata;
	vector<Igrac> vig;
public:
	void napuni_mac(Igrac& ig, Karta&k);
	void shuffle_mac();
	void deal_cards();
};