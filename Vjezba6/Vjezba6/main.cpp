#include "class.hpp"
//Napisite program u kojem nekoliko vlasnika dobija jednak broj ljubimaca i broj akcija koje
//moze s njima odraditi.U programu se trazi vlasnik najsretnijeg ljubimca.
/*void happiest_owner(vector<Owner>& vowner, vector<VirtualPet>& vpets, int num) {
	vector<VirtualPet>::iterator it = vpets.begin();
	for (Owner& own : vowner) {
		for (int i = 0; i < num; i++) {
			own.add_pet(*it);
			it++;
		}
	}
	for (Owner& own : vowner) {
		for (int i = 0; i < num; i++)
			own.owner_interact();
	}
	Owner happiest_owner = vowner[0];
	for (Owner& own : vowner) {
		for (VirtualPet& pet : own.get_pets()) {
			if (pet.get_happiness() > happiest_owner.get_pets()[0].get_happiness())
				happiest_owner = own;
		}
	}
	cout << "Vlasnik najsretnijeg ljubimca je:" << happiest_owner.get_name() << endl;
}
*/
int main(void) {
	VirtualPet
		frki("Frki", "Terijer"),
		zuli("Zuli", "Jazavcar"),
		crni("Crni", "CaneCorso"),
		bili("Bili", "Huskey"),
		ruzni("Ruzni", "Pitbull"),
		mrki("Mrki", "Argentinska doga"),
		smoki("Smoki", "Shitzu");
	Owner mate("Mate"),
		stipe("Stipe"),
		jure("Jure"),
		jakov("Jakov"),
		simun("Simun"),
		stjepan("Stjepan");
	mate.add_pet(frki);
	mate.add_pet(zuli);
	stipe.add_pet(crni); 
	stipe.add_pet(bili);
	jure.add_pet(ruzni);


	Owner mateo(jure), //cpy ctor
		sebastijan = std::move(stipe); //move ctor
	sebastijan.print_owner_pets();
	stipe.print_owner_pets();
	vector<Owner> vowner = { jakov,simun,stjepan };
	vector<VirtualPet> vpets = { frki, zuli, crni, bili, ruzni, mrki, smoki };
	//happiest_owner(vowner, vpets, 2);

	Owner fabijan = std::move(mate); //move ctor
	fabijan.print_owner_pets();
	mate.print_owner_pets();
	return 0;
}