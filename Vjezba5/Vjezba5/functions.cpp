#include "class.hpp"

void Mac::napuni_mac(Igrac& ig, Karta&k) {
	for (int i = 0; i < 4; i++) {
		if (i == 0) { k.set_zog("DENARI"); }
		if (i == 1) { k.set_zog("COPPE"); }
		if (i == 2) { k.set_zog("BASTONI"); }
		if (i == 3) { k.set_zog("SPADE"); }
		for (int j = 1; j <= 13; j++) {
			if (j == 8 || j == 9 || j == 10)
				continue;
			k.set_num(j);
			mac_karata.push_back(k);
			//k.print_card();
		}
	}
}
void Mac::shuffle_mac() {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(begin(mac_karata), end(mac_karata), default_random_engine(seed));
}
void Igrac::print_igrac_ruka() {
	for (int i = 0; i < 10; i++) {
		vruka[i].print_card();
	}
	cout << endl;
	cout << "broj bodova: " << bodovi << endl;
}
void Mac::deal_cards() {
	cout << "2 ili 4 igraca?" << endl;
	unsigned num_ply;
	cin >> num_ply;
	if (num_ply != 2 && num_ply != 4) {
		cout << "Broj igraca mora biti 2 ili 4!" << endl;
		return;
	}
	int j = 0;
	vig.reserve(num_ply);
	Igrac* ig = new Igrac[num_ply];
	for (int i = 0; i < num_ply; i++) {
		cout << "Unesite ime " << i + 1 << ". igracu:" << endl;
		string ime;
		cin >> ime;
		ig[i].set_name_plyr(ime);
		for (j; j < (i+1)*10;) {
			ig[i].fill_hand(mac_karata[j]);
			j++;
		}
		ig[i].akuza();
		ig[i].napolitana();
		vig.push_back(ig[i]);
		vig[i].print_igrac_ruka();
	}
}
void Igrac::akuza() {
	unsigned cnt1=0, cnt2=0, cnt3=0;
	for (int i = 0; i < 10; i++) {
		unsigned br; string str;
		vruka[i].get_num_zog(&br, str);
		if (br == 1) { cnt1++; }
		if (br == 2) { cnt2++; }
		if (br == 3) { cnt3++; }
	}
	if (cnt1 >= 3) { bodovi += cnt1; }
	if (cnt2 >= 3) { bodovi += cnt2; }
	if (cnt3 >= 3) { bodovi += cnt3; }
}
void Igrac::napolitana() {
	for (int i = 0; i < 10; i++) {
		unsigned br; string zog;
		vruka[i].get_num_zog(&br, zog);
		if (br == 1) {
			for (int j = 0; j < 10; j++) {
				unsigned br2; string zog2;
				vruka[j].get_num_zog(&br2, zog2);
				if (br2 == 2 && zog2 == zog) {
					for (int k = 0; k < 10; k++) {
						unsigned br3; string zog3;
						vruka[k].get_num_zog(&br3, zog3);
						if (br3 == 3 && zog3 == zog) {
							cout << "NAPOLITANA " << zog << endl;
							bodovi += 3;
						}
					}
				}
			}
		}
	}
}
