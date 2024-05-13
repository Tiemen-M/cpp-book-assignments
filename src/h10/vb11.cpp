// Created by Tiemen Molenaar in 2023
// voorbeeld 10.11
#include <iostream>
#include <string>

using namespace std;

namespace vb_11 {
	class Bestuurslid;

	class Clublid {
	private:
		string lidnaam;
		int lidnr;
	public:
		Clublid(const string& naam = "geen", int nr = 0);
		operator Bestuurslid();
		friend ostream& operator<<(ostream& uit, const Clublid& x);
	};

	class Bestuurslid {
	private:
		string bestuurslidnaam;
		int bestuurslidnr;
	public:
		Bestuurslid(const string& naam = "geen", int nr = 0);
		operator Clublid();
		friend ostream& operator<<(ostream& uit, const Bestuurslid& x);
	};
}

using namespace vb_11;

void main_vb_11() {
	Clublid c1("Hiawatha", 24), c2("Midas", 57);
	Bestuurslid b1, b2("Wolfje", 7);

	b1 = c2;
	cout << "Het bestuur" << endl;
	cout << b1 << endl;
	cout << b2 << endl;

	Clublid c3 = b2;
	cout << endl << "De leden" << endl;
	cout << c1 << endl << c2 << endl << c3 << endl;
}

Clublid::operator Bestuurslid() {
	return Bestuurslid(lidnaam, lidnr);
}

Clublid::Clublid(const string& naam, int nr)
	: lidnaam(naam), lidnr(nr) {}

ostream& vb_11::operator<<(ostream& uit, const Clublid& x) {
	return uit << "Lid: " << x.lidnaam << ", " << x.lidnr;
}

Bestuurslid::Bestuurslid(const string& naam, int nr)
	: bestuurslidnaam(naam), bestuurslidnr(nr) {}

Bestuurslid::operator Clublid() {
	return Clublid(bestuurslidnaam, bestuurslidnr);
}

ostream& vb_11::operator<<(ostream& uit, const Bestuurslid& x) {
	return uit << "Bestuurslid: " << x.bestuurslidnaam;
}