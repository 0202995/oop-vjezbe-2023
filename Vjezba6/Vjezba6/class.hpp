#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <random>
using namespace std;

class VirtualPet {
	string ime;
	string vrsta;
	int glad;
	int sreca;
	bool budnost;
public:
	VirtualPet(string name, string type) {
		ime = name; vrsta = type; glad = 0; sreca = 10; budnost = true;
	}
	void sleep() {
		if (!budnost) {
			return;
		}
		glad+=2; 
		sreca+=4; 
		budnost = false;
	}
	void feed() { 
		if (glad <= 3) {
			sleep();
			return;
		}
		glad-=5; 
		sreca+=5; 
	}
	void play() {
		glad += 7;;
		sreca += 7; 
	}
	const int get_happiness() {
		return this->sreca;
	}
	void print_pet() { cout << ime << " " << vrsta << " Glad: " << glad << " Sreca: " << sreca << endl; }
};

class Owner {
	string name;
	vector<VirtualPet> vpets;
public:
	Owner(string s) { name =s; }
	Owner(const Owner& other) : vpets(other.vpets), name(other.name) {}
	Owner(Owner&& other) noexcept: name(std::move(other.name)), vpets(std::move(other.vpets)) {}
	void add_pet(VirtualPet&p) {
		vpets.push_back(p);
	}
	void owner_interact();
	vector<VirtualPet>& get_pets() {
		return vpets;
	}
	string& get_name() { return name; }
	int get_happiness(VirtualPet pet) {
		return pet.get_happiness();
	}
	void print_owner_pets() {
		for (int i=0; i < vpets.size(); i++) {
			vpets[i].print_pet();
		}
	}
};
