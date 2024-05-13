// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace opg_3 {
	class Maand {
	private:
		const char* MAAND_NAAM[12] = {"Januari","Februari","Maart","April","Mei","Juni","juli","Augustus","September","Oktober","November","December"};
		const char* DAG_NAAM[7] = { "Ma","Di","Wo","Do","Vr","Za","Zo" };
		const int eenJanuari1980;
		int maandnummer;
		int jaartal;
		bool isSchrikkeljaar(int jaar) const;
		int getAantalDagen(int maand, int jaar) const;
		int getEersteDagMaand(int maand, int jaar) const;
	public:
		Maand(int nummer, int jaar);
		void print() const;
	};
}

using namespace opg_3;

void main_opg_3() {
	Maand m(10, 2023);
	m.print();

	Maand t(6, 2006);
	t.print();

	Maand t2(10, 3000);
	t2.print();
}

Maand::Maand(int nummer = 10, int jaar = 2023) :
	maandnummer(nummer), jaartal(jaar), eenJanuari1980(1) {}

bool Maand::isSchrikkeljaar(int jaar) const {
	return jaar % 4 == 0 && 
		jaar % 100 != 0 ||
		jaar % 400 == 0;
}

int Maand::getAantalDagen(int maand, int jaar) const {
	switch (maand) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;

	case 4:
	case 6:
	case 9:
	case 11: return 30;

	case 2:
		if (isSchrikkeljaar(jaar))
			return 29;
		else
			return 28;
	}

	return 0;
}

int Maand::getEersteDagMaand(int maand, int jaar) const {
	// De telling begin op eenKanuari1980
	int dag = eenJanuari1980-1;

	// ga eerst tot alle hele complete jaren
	for (int j = 1980; j < jaar; j++) {
		for (int m = 1; m <= 12; m++) {
			dag += getAantalDagen(m, j);
			dag %= 7;
		}
	}

	// nu berkenen we de betrefende jaar er bij
	for (int m = 1; m < maand; m++) {
		dag += getAantalDagen(m, jaar);
		dag %= 7;
	}

	// nu ga we naar de erste dag van de opgegeefde maand
	return (dag + 1) % 7;
}

void Maand::print() const {
	// titel van kalender
	cout << MAAND_NAAM[maandnummer - 1] << " " << jaartal << endl;
	
	// geneereer kalender buffer die bepaalt op welke positie welke dag afgedrukt moet worden
	int kalender[6][7];
	int eerste_dag = getEersteDagMaand(maandnummer, jaartal);
	int aantal_dagen = getAantalDagen(maandnummer, jaartal);
	int teller = 0;
	int dagen_teller = 1;
	for (int x = 0; x < 6; x++) {
		for (int y = 0; y < 7; y++) {
			if (teller >= eerste_dag && (teller - eerste_dag) < aantal_dagen) {
				kalender[x][y] = dagen_teller;
				dagen_teller++;
			}
			else {
				kalender[x][y] = 0;
			}
			teller++;
		}
	}

	// teken de kalender
	for (int rij = 0; rij < 7; rij++) {
		cout << setw(5) << left << DAG_NAAM[rij];
		for (int kolom = 0; kolom < 6; kolom++) {
			int dag_nummer = kalender[kolom][rij];
			cout << setw(5) << left;
			if (dag_nummer == 0)
				cout << "";
			else
				cout << dag_nummer;
		}
		cout << endl;
	}
}