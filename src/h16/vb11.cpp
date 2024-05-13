// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.11 I/O met verbeterde invoer van objecten
#include <iostream>
#include <cctype>
using namespace std;

namespace vb_11 {
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

	// Implementatie operatoren
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

using namespace vb_11;

void main_vb_11() {
	Punt A, B;
	cout << "Voer de coordinaten van 2 punten in:" << endl;
	cin >> A >> B;
	cin.get();
	cout << "A is : " << A << endl;
	cout << "B is : " << B << endl;
}