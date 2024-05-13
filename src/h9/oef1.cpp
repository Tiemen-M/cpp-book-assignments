// Created by Tiemen Molenaar in 2023
// vragen, oefeningen en testen
#include <iostream>
#include <iomanip>

using namespace std;

class Counter {
private:
	int vrouw, man;
public:
	Counter() : vrouw(0), man(0) {}
	void verhoogVrouw() { ++vrouw; }
	void verhoogMan() { ++man; }
	void zetOpNul() { vrouw = 0; man = 0; }
	void print() const {
		cout << "(vrouw:" << vrouw << ",man:" << man << ")" << endl;
	}
	void loop() {
		cout << "Typ q + enter om te stoppen." << endl;
		for (char toets = ' '; toets != 'q'; cin >> toets) {
			switch (toets) {
			case 'v':
				verhoogVrouw();
				break;
			case 'm':
				verhoogMan();
				break;
			case 'n':
				zetOpNul();
				break;
			}
			print();
		}
	}
};

class Tijd {
private:
	unsigned uren, minuten, seconden;
public:
	Tijd(unsigned uren=0, unsigned minuten=0, unsigned seconden=0) :
		uren(uren), minuten(minuten), seconden(seconden) {
	}

	void setTijd(unsigned uren, unsigned minuten, unsigned seconden) {
		this->uren = uren;
		this->minuten = minuten;
		this->seconden = seconden;
	}

	void print() const;
};

void main_oef_1() {
	Tijd tijd(15, 5, 3);
	tijd.print();
	tijd.setTijd(10, 0, 50);
	tijd.print();

	Counter c;
	c.loop();
}

void Tijd::print() const {
	cout << setw(2) << uren << ":"
		<< setw(2) << minuten << ":"
		<< setw(2) << seconden << endl;
}