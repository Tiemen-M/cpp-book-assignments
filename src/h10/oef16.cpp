// Created by Tiemen Molenaar in 2023
// oef16 conversie van Persoon naar Clublid
#include <iostream>
#include <iomanip>
using namespace std;

namespace oef_16 {
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

	class Clublid {
	private:
		string naam;
		Datum gebdat;
	public:
		Clublid(string naam, const Datum& gebdat) :
			naam(naam), gebdat(gebdat) {}

		friend ostream& operator<<(ostream& uit, const Clublid& c) {
			return uit << "Clublid: " << c.naam << ", " << c.gebdat;
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

		operator Clublid () const {
			return Clublid(naam, gebdat);
		}
	};
}

using namespace oef_16;

void main_oef_16() {
	// ineficent the constructerd are called: copy-constructor and 3-int-argument-constructor
	Persoon p1("Tiemen", Datum(8, 5, 2000));
	cout << p1 << endl;

	// more efficnet: only one constructor is called
	Persoon p2("Zero", 10, 4, 2012);
	cout << p2 << endl;

	// conversie van Persoon naar Clublid
	Clublid c1 = p1;
	cout << p1 << " Converseert naar clublid: " << c1 << endl;
}