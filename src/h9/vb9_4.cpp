// Created by Tiemen Molenaar in 2023
// Voorbeeld 9.4 Default-constructor met default-argumenten
#include <iostream>
#include <iomanip>
using namespace std;

class Datum {
private:
	int dag;
	int maand;
	int jaar;
public:
	Datum(int d = 1, int m = 1, int j = 2000) {
		dag = d;
		maand = m;
		jaar = j;
	}

	void setDatum(int d, int m, int j) {
		dag = d;
		maand = m;
		jaar = j;
	}
	void print();
};

void main_vb_9_4() {
	// Declaratie en initialisatie met 1 januari 2000
	Datum d1;

	d1.print();
	d1.setDatum(23, 9, 1975);
	d1.print();

	// Declaratie en initialisatie met 5 mei 1945
	Datum d2(5, 5, 1945);
	d2.print();
}

void Datum::print() {
	cout << setfill('0') << setw(2) << dag << '-'
		<< setw(2) << maand << '-'
		<< setw(4) << jaar << endl;
}