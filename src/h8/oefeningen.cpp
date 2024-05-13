// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Persoonsgegevens {
	string naam, voorleters,adres, postcode, woonplaats;
	int telefoonnummer[10];
};

struct Datum {
	unsigned dag, maand, jaar;
};

struct Punt {
	signed x, y;
};

struct Bankrekening {
	string tenaamstelling, rekeningnummer;
	double saldo;
};

struct Autogegevens {
	string merk, type;
	unsigned bouwjaar;
	double aanschafprijs;
};

enum Datatype {
	PERSOONSGEGEVENS,
	DATUM,
	PUNT,
	BANKREKENING,
	AUTOGEGEVENS
};

union Data_union {
	struct Persoonsgegevens persoongegevens;
	struct Datum datum;
	struct Punt punt;
	struct Bankrekening bankrekening;
	struct Autogegevens autogegevens;
};

struct Data {
	enum Datatype type;
	union Data_union data;
};

void print(const struct Data&);

void main_oef() {
	vector<Data> v;
	Data d;



}

void print(const struct Data& data) {
	cout << "--------------------" << endl;
	switch (data.type) {
	case PERSOONSGEGEVENS:
		cout << "Persoonsgegevens" << endl;
		cout << "Naam: " << data.data.persoongegevens.naam << endl;
		cout << "Voorletters: " << data.data.persoongegevens.voorleters << endl;
		cout << "Adres: " << data.data.persoongegevens.adres << endl;
		cout << "Postcode: " << data.data.persoongegevens.postcode << endl;
		cout << "Woonplaats: " << data.data.persoongegevens.woonplaats << endl;
		cout << "telefoonnummer: " << data.data.persoongegevens.telefoonnummer << endl;
		break;
	case DATUM:
		cout << "Datum";
		cout << "Dag " << data.data.datum.dag << " van maand " 
			<< data.data.datum.maand << " van het jaar " 
			<< data.data.datum.jaar << endl;
		break;
	case PUNT:
		cout << "(" << data.data.punt.x << "," << data.data.punt.y << ")" << endl;
		break;
	case BANKREKENING:
		cout << "Bankrekening" << endl;
		cout << "Tenaamstelling: " << data.data.bankrekening.tenaamstelling << endl;
		cout << "Rekeningnummer: " << data.data.bankrekening.rekeningnummer << endl;
		cout << "Saldo: " << data.data.bankrekening.saldo << endl;
		break;
	case AUTOGEGEVENS:
		cout << "Autogegevens" << endl;
		cout << "Merk: " << data.data.autogegevens.merk << endl;
		cout << "Type: " << data.data.autogegevens.type << endl;
		cout << "Bouwjaar: " << data.data.autogegevens.bouwjaar << endl;
		cout << "Aanschafprijs: " << data.data.autogegevens.aanschafprijs << endl;
		break;
	}
	cout << "--------------------" << endl;
}