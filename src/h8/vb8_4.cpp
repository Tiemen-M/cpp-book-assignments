// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Persoon {
	string naam;
	int lengte;
	double gewicht;
};

void lees(struct Persoon& p);
void print(const struct Persoon& p);
void maakBufferLeeg();

void main_8_4() {
	const int AANTAL = 3;
	vector<struct Persoon> personenLijst;
	Persoon p;

	for (int i = 0; i < AANTAL; i++) {
		lees(p);
		personenLijst.push_back(p);
	}

	cout << "De ingevoerde gegevens zijn:" << endl;
	vector<struct Persoon>::iterator pos,
		einde = personenLijst.end();
	for (pos = personenLijst.begin(); pos != einde; ++pos)
		print(*pos);
}

void lees(struct Persoon& p) {
	cout << "Naam: ";
	getline(cin, p.naam);

	cout << "Lengte: ";
	cin >> p.lengte;
	maakBufferLeeg();

	cout << "Gewicht: ";
	cin >> p.gewicht;
	maakBufferLeeg();
	cout << endl;
}

void maakBufferLeeg() {
	string temp;
	getline(cin, temp);
}

void print(const struct Persoon& p) {
	cout << p.naam << " is "
		<< p.lengte << " cm en weegt "
		<< p.gewicht << " kg." << endl;
}