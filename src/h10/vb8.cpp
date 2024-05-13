// Created by Tiemen Molenaar in 2023
// Voorbeeld 10.8 Persoon en Datum
#include <iostream>
#include <iomanip>
using namespace std;

namespace vb_8 {
	class Datum {
	private:
		int dag, maand, jaar;
	public:
		Datum(int dag = 0, int maand = 0, int jaar = 0)
			: dag(dag), maand(maand), jaar(jaar) {}
		friend ostream& operator<<(ostream& uit, const Datum& datum) {
			return uit << setfill('0')
				<< setw(2) << datum.dag << '-'
				<< setw(2) << datum.maand << '-'
				<< setw(4) << datum.jaar;
		}
	};

	class Persoon {
	private:
		string naam;
		Datum gebdat;
	public:
		Persoon(const char* n, Datum gd)
			: naam(n), gebdat(gd) {}
		Persoon(const char* naam, int dag = 0, int maand = 0, int jaar = 0)
			: naam(naam), gebdat(dag, maand, jaar) {}

		friend ostream& operator<<(ostream& uit, const Persoon& p) {
			return uit << p.naam << ", " << p.gebdat;
		}
	};
}

using namespace vb_8;

void main_vb_8() {
	// ineficent the constructerd are called: copy-constructor and 3-int-argument-constructor
	Persoon p1("Tiemen", Datum(8, 5, 2000));
	cout << p1 << endl;

	// more efficnet: only one constructor is called
	Persoon p2("Zero", 10, 4, 2012);
	cout << p2 << endl;
}