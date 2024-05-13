// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 11.11.1 door Tiemen Molenaar in oktober 2023
// Erg inefficente code!! alleen maar om meerdere type klassen in één vector te stoppen.
#include <iostream>
#include <vector>
#include "maand.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
using namespace maand;

namespace opg_1 {
	const int GROOTE_EERSTE_KOLOM = 25;

	enum Type {
		TYPE_UITGAVE,
		TYPE_TIJDSCHRIFT,
		TYPE_BOEK,
		TYPE_CD
	};

	class Uitgave {
	protected:
		string titel;
		double prijs;
		enum Type type;
	public:
		Uitgave(string, double, Type);
		string toString() const;
		Type getType() const;
	};

	class Tijdschrift : public Uitgave {
	private:
		Maand uitgaveMaand;
	public:
		Tijdschrift(string, double, Maand);
		string toString() const;
	};

	class Boek : public Uitgave {
	private:
		int aantalBladzijdes;
		string auteur;
	public:
		Boek(string, double, int, string);
		string toString() const;
	};

	class CD : public Uitgave {
	private:
		unsigned speeltijdInMinuten;
	public:
		CD(string, double, unsigned);
		string toString() const;
	};

	union Item {
		Uitgave *uitgave;
		Tijdschrift *tijdschrift;
		Boek *boek;
		CD *cd;
	};

	ostream& operator<<(ostream& uit, Item&);
}

using namespace opg_1;

void main_opg_1() {
	// Declareer en initialiseer vector
	vector<union Item> winkel;
	union Item x;

	// voeg een boek toe
	Boek b = Boek("Mijn eigen taal", 10.00, 100, "Tiemen");
	x.boek = &b;
	winkel.push_back(x);
	
	// voeg een tijdschrift toe
	Tijdschrift t = Tijdschrift("Donald duck", 9.99, MAART);
	x.tijdschrift = &t;
	winkel.push_back(x);
	
	// voeg een cd toe
	CD c = CD("The final countdown", 7.99, 120);
	x.cd = &c;
	winkel.push_back(x);
	
	// Print de inhoud van de vector
	vector<union Item>::iterator pos;
	for (pos = winkel.begin(); pos < winkel.end(); ++pos) {
		cout << *pos << endl;
		cout << endl;
	}
}

// implementatie klasse Uitgave
Uitgave::Uitgave(string titel, double prijs, Type type= TYPE_UITGAVE)
	: titel(titel), prijs(prijs), type(type) {}

string Uitgave::toString() const {
	ostringstream os;
	const int g = GROOTE_EERSTE_KOLOM;
	os
		<< setw(g) << left << "Titel:" << titel << endl
		<< setw(g) << left << "Prijs:" << prijs << endl;
	return os.str();
}

Type Uitgave::getType() const {
	return type;
}

ostream& opg_1::operator<<(ostream& uit, union Item& x) {
	switch (x.uitgave->getType()) {
	case TYPE_TIJDSCHRIFT:
		return uit << x.tijdschrift->toString();
	case TYPE_BOEK:
		return uit << x.boek->toString();
	case TYPE_CD:
		return uit << x.cd->toString();
	default:
		return uit << x.uitgave->toString();
	}
}

// implementatie klasse Tijdschrift
Tijdschrift::Tijdschrift(string titel, double prijs, Maand uitgaveMaand)
	: Uitgave(titel, prijs, TYPE_TIJDSCHRIFT), uitgaveMaand(uitgaveMaand) {}

string Tijdschrift::toString() const {
	ostringstream os;
	const int g = GROOTE_EERSTE_KOLOM;
	os 
		<< ">>>Uitgave Tijdschrift<<<" << endl
		<< Uitgave::toString()
		<< setw(g) << left << "Uitgave maand:" << MAAND_NAAM[uitgaveMaand] << endl;
	return os.str();
}

// Implementatie klasse Boek
Boek::Boek(string titel, double prijs, int aantalBladzijdes, string auteur) 
	: Uitgave(titel, prijs, TYPE_BOEK), aantalBladzijdes(aantalBladzijdes), auteur(auteur) {}

string Boek::toString() const {
	ostringstream os;
	const int g = GROOTE_EERSTE_KOLOM;
	os
		<< ">>>Uitgave Boek<<<" << endl
		<< Uitgave::toString()
		<< setw(g) << left << "Aantal bladzijdes:" << aantalBladzijdes << endl
		<< setw(g) << left << "Auteur:" << auteur << endl;
	return os.str();
}

// Implementatie klasse CD
CD::CD(string titel, double prijs, unsigned speeltijdInMinuten)
	: Uitgave(titel, prijs, TYPE_CD),speeltijdInMinuten(speeltijdInMinuten) {}

string CD::toString() const {
	ostringstream os;
	const int g = GROOTE_EERSTE_KOLOM;
	os
		<< ">>>Uitgave CD<<<" << endl
		<< Uitgave::toString()
		<< setw(g) << left << "Speeltijd:" << speeltijdInMinuten << " minuten" << endl;
	return os.str();
}


