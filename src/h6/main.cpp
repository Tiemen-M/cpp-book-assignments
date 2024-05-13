// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>

using namespace std;

void calcGem();
void fillRam();

int main() {
	//calcGem();
	//fillRam();

	char test[100] = {};
	for(int i=0; i < 100; i++)
		cout << setw(9) << hex << +test[i] << ((!((i+1)%5)) ? "\n" : "");
}

void fillRam() {
	const unsigned long LARGE = 10240;
	int ram[LARGE];

	for (unsigned long i = 0; i < LARGE; i++) {
		ram[i] = i;
		cout << setw(10) << i;
	}

	cin.get();

}

void calcGem() {
  unsigned long nummer[5];
  double gemmidelde;
  const int AANTAL_GETALLEN=5;
	// Vraag gebruiker om 5 getallen in te voeren.
	gemmidelde = 0;
	for (int i = 0; i < AANTAL_GETALLEN; i++) {
		cout << "Voer het " << (i + 1) << "e nummer in: ";
		cin >> nummer[i];
		cin.get();
		cout << endl;

		// bereken iteratief het gemmidelde
		gemmidelde += nummer[i];
	}
	gemmidelde /= AANTAL_GETALLEN;

	// print het resultaat
	cout << "je hebt de volgende nummers ingevoerd:" << endl;
	for (int i = 0; i < AANTAL_GETALLEN; i++) {
		cout << setw(6) << nummer[i];
	}
	cout << endl;
	cout << "Het gemmidelde is " << setprecision(1) << gemmidelde << endl;
}
