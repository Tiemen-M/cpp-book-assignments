// Created by Tiemen Molenaar in 2023
// voorbeeld 10.10 Clublid en Bestuurslid
#include <iostream>
#include <string>
using namespace std;

namespace vb_10 {
	class Clublid {
	private:
		string lidnaam;
		int lidnr;
	public:
		Clublid(const char*, int);
		friend ostream& operator<<(ostream& uit, const Clublid& x);
	};

	class Bestuurslid {
	private:
		string bestuurslidnaam;
		int bestuurslidnr;
	public:
		Bestuurslid(const char*, int);
		friend ostream& operator<<(ostream& uit, const Bestuurslid& x);
	};
}

using namespace vb_10;

void main_vb_10() {
	Clublid 
		c1("Hiawatha", 24),
		c2("Midas", 57);

	cout << "De leden:" << endl;
	cout << c1 << endl;
	cout << c2 << endl;

	Bestuurslid b1("Midas", 57);
	cout << "Het bestuur: " << endl;
	cout << b1 << endl;
}

Clublid::Clublid(const char* naam = "Geen naam", int nr = 0)
	: lidnaam(naam), lidnr(nr) {}

ostream& vb_10::operator<<(ostream& uit, const Clublid& x) {
	return uit << x.lidnaam << ", " << x.lidnr;
}

Bestuurslid::Bestuurslid(const char* naam = "Geen", int nr = 0)
	: bestuurslidnaam(naam),bestuurslidnr(nr) {}

ostream& vb_10::operator<<(ostream& uit, const Bestuurslid& x) {
	return uit << x.bestuurslidnaam;
}