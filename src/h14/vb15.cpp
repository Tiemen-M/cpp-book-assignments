// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.15 Zelfgedefinieerd type en copy()
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

namespace vb_15 {
	class Persoon {
	private:
		int nr;
		string naam;
	public:
		// Klasse moet default-constructor
		Persoon(int nr=0, string naam="")
			: naam(naam), nr(nr) {
		}

		// klasse moet getters hebben
		int getNr() const {
			return nr;
		}
		string getNaam() const {
			return naam;
		}
		
		// KLasse moet setters hebben
		void setNr(int n) {
			nr = n;
		}
		void setNaam(const string& n) {
			naam = n;
		}
	};

	// Implementatiie van globale operatorfuncties
	ostream& operator<<(ostream& uit, const Persoon& p) {
		return uit << p.getNr() << ' ' << p.getNaam() << endl;
	}

	istream& operator>>(istream& in, Persoon& p) {
		int nr;
		string naam;

		in >> nr;
		p.setNr(nr);

		in >> naam;
		p.setNaam(naam);

		return in;
	}
}

using namespace vb_15;

void main_vb_15() {
	Persoon p1(1, "Gertjan"), p2(2, "Charlotte");
	// Vul een vector
	vector<Persoon> v;
	v.push_back(p1);
	v.push_back(p2);

	// Maak een bestand
	ofstream uit("test.txt");
	copy(v.begin(), v.end(), ostream_iterator<Persoon>(uit));
	uit.close();

	// Zet inhoud vector op het scherm
	cout << "Van vector naar scherm:" << endl;
	copy(v.begin(), v.end(), ostream_iterator<Persoon>(cout));

	// Zet inhoud bestand op het scherm
	ifstream in("test.txt");
	cout << "Van bestand naar het scherm:" << endl;
	copy(istream_iterator<Persoon>(in), 
		istream_iterator<Persoon>(), 
		ostream_iterator<Persoon>(cout));
	in.close();

}