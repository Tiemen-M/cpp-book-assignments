// Created by Tiemen Molenaar in 2023
#include <iostream>

using namespace std;

struct Artikel {
	string omschrijving;
	unsigned nummer;
	double prijs;
};

void print(const struct Artikel&);

int main_eigen_1() {
	struct Artikel art1 = {"cd-rom speller",489238, 29.99};
	print(art1);
	Artikel art2 = art1;
	print(art2);
	cout << "Adress art1 : " << &art1 << endl;
	cout << "Adress art2 : " << &art2 << endl;


	return 0;
}

void print(const struct Artikel& art) {
	cout << "Omschriving : " << art.omschrijving << endl;
	cout << "Nummer      : " << art.nummer << endl;
	cout << "Prijs       : " << art.prijs << " EURO" << endl;
}