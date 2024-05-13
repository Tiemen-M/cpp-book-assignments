// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.4
#include <iostream>
#include <iomanip>
using namespace std;

namespace vb_4 {
	// basis klasse
	class Rekening {
	protected:
		int nummer;
		string naam;
		double saldo;
	public:
		Rekening(int nummer, const string& naam)
			: nummer(nummer), naam(naam), saldo(0.0) {
		}

		void print() const {
			cout
				<< "Nummer:   " << nummer << endl
				<< "Naam:     " << naam << endl
				<< "Saldo:    "
				<< setprecision(2) << showpoint << fixed
				<< saldo << endl;
		}

		void stort(double bedrag) {
			saldo += bedrag;
		}

		void naamOp(double bedrag) {
			// pre: saldo is voldoende om bedrag op te nemen
			saldo -= bedrag;
		}
	};

	// afgeleide klasse
	class SpaarRekening : public Rekening {
	private:
		double percentage;
	public:
		SpaarRekening(int nummer, const string& naam, double percentage)
			: Rekening(nummer, naam), percentage(percentage) {}

		void print() const {
			Rekening::print();
			cout << "Rente:    " << percentage << "%" << endl;
		}

		void schrijfRenteBij() {
			double rente = saldo * percentage / 100;
			saldo += rente;
		}
	};

	// nog een afgeleide klasse
	class SalarisRekening : public Rekening {
	private:
		string werkgever;
	public:
		SalarisRekening(int nummer, const string& naam, const string& werkgever)
			: Rekening(nummer, naam), werkgever(werkgever) {}

		void print() const {
			Rekening::print();
			cout << "Werkgever: " + werkgever << endl;
		}
	};
}

using namespace vb_4;

void main_vb_4() {
	SpaarRekening spaarR(123, "Guy", 4.0);
	SalarisRekening salarisR(555, "Christel", "Hogeschool");

	spaarR.print();
	cout << endl;
	salarisR.print();
}