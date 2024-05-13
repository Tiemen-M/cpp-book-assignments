// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.12 I/O van objecten naar en van een bestand
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

namespace vb_12 {
	class Punt {
	private:
		int x, y;
	public:
		Punt(int x = 0, int y = 0)
			: x(x), y(y) {
		}
		friend ostream& operator<<(ostream& uit, const Punt& p);
		friend istream& operator>>(istream& in, Punt& p);
	};

	void skip(istream& in) {
		// pre: er is nog iets te lezen in de stream in
		char ch;
		do {
			in >> ch;
		} while (in && !isdigit(ch) && ch != '-');
		if (in)
			in.putback(ch);
	}

	// Implementatie van de operatoren
	ostream& operator<<(ostream& uit, const Punt& p) {
		return uit << '(' << p.x << ',' << p.y << ')';
	}

	istream& operator>>(istream& in, Punt& p) {
		skip(in);
		in >> p.x;
		skip(in);
		in >> p.y;
		return in;
	}
}

using namespace vb_12;

void main_vb_12() {
	Punt A(4, 5), B(10, 100);
	
	string filename = "bestand4.txt";
	ofstream uitvoer(filename.c_str());
	uitvoer << A << B;
	uitvoer.close();

	ifstream invoer(filename.c_str());
	Punt P, Q;
	invoer >> P >> Q;
	invoer.close();

	cout << "P is: " << P << endl;
	cout << "Q is: " << Q << endl;
}

void main_vb_12_b() {
	Punt A(-4, -5), B(10, 100);
	string filename = "bestand4.txt";
	fstream bestand;

	bestand.open(filename.c_str(), ios::out);
	bestand << A << B;
	bestand.close();

	Punt P, Q;
	bestand.open(filename.c_str(), ios::in);
	bestand >> P >> Q;
	bestand.close();

	cout << "P is " << P << endl;
	cout << "Q is " << Q << endl;
}

void main_vb_12_c() {
	Punt A(-4, -5), B(10, 100);
	string filename = "bestand4.txt";
	fstream bestand(filename.c_str(), ios::trunc | ios::in | ios::out);

	bestand.seekp(0);
	bestand << A << B;

	Punt P, Q;
	bestand.seekg(0);
	bestand >> P >> Q;
	cout << "Get pointer is " << bestand.tellg() << endl;
	cout << "Put pointer is " << bestand.tellp() << endl;
	bestand.clear();
	bestand.seekg(0, ios::beg);
	cout << "Na clear en seekg(0, ios::beg) is de get file pointer: " << bestand.tellg() << endl;

	Punt P2, Q2;
	bestand >> P2 >> Q2;

	bestand.close();

	cout << "P is " << P << endl;
	cout << "Q is " << Q << endl;
	cout << "P2 is " << P2 << endl;
	cout << "Q2 is " << Q2 << endl;
}